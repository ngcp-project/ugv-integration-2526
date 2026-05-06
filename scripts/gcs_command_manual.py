#!/usr/bin/env python3
"""GCS display — starts the XBee link and shows all sent commands and Jetson replies.

Run gcs_command_sender.py in a separate terminal to send commands.

Usage:
    python scripts/gcs_command_manual.py --xbee-port COM3 --vehicle-mac 0013A20042839F3E
"""
import argparse
import json
import os
import socket
import sys
import threading
import time

repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(repo_root, 'lib', 'gcs-infrastructure', 'Application'))
sys.path.insert(0, os.path.join(repo_root, 'lib', 'gcs-packet', 'Packet'))

from Infrastructure.InfrastructureInterface import (
    LaunchGCSXBee, SendCommand, ReceiveTelemetry,
)
from Command.Heartbeat import Heartbeat
from Command.EmergencyStop import EmergencyStop
from Command.AddZone import AddZone
from Command.PatientLocation import PatientLocation
from Enum.ConnectionStatus import ConnectionStatus
from Enum.ZoneType import ZoneType
from Enum.Vehicle import Vehicle
from PacketLibrary.PacketLibrary import PacketLibrary

DEFAULT_CMD_PORT = 5556

_count = 0
_count_lock = threading.Lock()


def display(msg):
    print(msg, file=sys.stderr, flush=True)


def telemetry_listener():
    while True:
        try:
            telem = ReceiveTelemetry()
            display(
                f'  <- REPLY  '
                f'CmdID={telem.CommandID}  PktID={telem.PacketID}  '
                f'Speed={telem.Speed:.3f}  Yaw={telem.Yaw:.3f}  '
                f'Pos=({telem.CurrentPositionX:.6f}, {telem.CurrentPositionY:.6f})  '
                f'Status={telem.VehicleStatus}  '
                f'MsgFlag={telem.MessageFlag}'
            )
        except Exception as e:
            display(f'  <- REPLY ERROR: {e}')
            time.sleep(1)


def execute_command(request):
    global _count
    cmd_id = request.get('cmd')
    cmd = None
    label = ''

    if cmd_id == 1:
        cmd = Heartbeat(ConnectionStatus.Connected)
        label = 'Heartbeat (Connected)'
    elif cmd_id == 2:
        cmd = Heartbeat(ConnectionStatus.Disconnected)
        label = 'Heartbeat (Disconnected)'
    elif cmd_id == 3:
        cmd = EmergencyStop(0)
        label = 'EmergencyStop (ACTIVATE)'
    elif cmd_id == 4:
        cmd = EmergencyStop(1)
        label = 'EmergencyStop (RELEASE)'
    elif cmd_id == 5:
        coords = [tuple(c) for c in request.get('coordinates', [])]
        cmd = AddZone(ZoneType.KeepIn, coords)
        label = f'AddZone (KeepIn, {len(coords)} coords)'
    elif cmd_id == 6:
        coords = [tuple(c) for c in request.get('coordinates', [])]
        cmd = AddZone(ZoneType.KeepOut, coords)
        label = f'AddZone (KeepOut, {len(coords)} coords)'
    elif cmd_id == 7:
        cmd = PatientLocation((0.0, 0.0))
        label = 'PatientLocation (Jetson will use Xsens GPS)'
    else:
        return {'ok': False, 'error': f'Unknown command: {cmd_id}'}

    cmd.Vehicle = Vehicle.MRA
    SendCommand(cmd, Vehicle.MRA)

    with _count_lock:
        _count += 1
        seq = _count

    display(f'\n[{seq}] SENT -> {label}')
    if cmd_id in (5, 6):
        for i, c in enumerate(request.get('coordinates', [])):
            display(f'       coord {i+1}: ({c[0]:.6f}, {c[1]:.6f})')

    return {'ok': True, 'label': label}


def handle_client(conn):
    buf = ''
    try:
        while True:
            data = conn.recv(4096)
            if not data:
                break
            buf += data.decode('utf-8')
            while '\n' in buf:
                line, buf = buf.split('\n', 1)
                line = line.strip()
                if not line:
                    continue
                try:
                    request = json.loads(line)
                    response = execute_command(request)
                except json.JSONDecodeError as e:
                    response = {'ok': False, 'error': f'Invalid JSON: {e}'}
                except Exception as e:
                    response = {'ok': False, 'error': str(e)}
                conn.sendall((json.dumps(response) + '\n').encode('utf-8'))
    except (ConnectionResetError, BrokenPipeError, OSError):
        pass
    finally:
        conn.close()


def command_server(port):
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    srv.bind(('127.0.0.1', port))
    srv.listen(1)
    display(f'Waiting for command sender on port {port}...\n')

    while True:
        conn, addr = srv.accept()
        display(f'Command sender connected.')
        threading.Thread(target=handle_client, args=(conn,), daemon=True).start()


def main():
    parser = argparse.ArgumentParser(description='GCS display — shows sent commands and telemetry')
    parser.add_argument('--xbee-port', required=True, help='Serial port for GCS XBee (e.g. COM3)')
    parser.add_argument('--vehicle-mac', default='0013A20042839F3E',
                        help='64-bit MAC of the vehicle XBee')
    parser.add_argument('--cmd-port', type=int, default=DEFAULT_CMD_PORT,
                        help=f'TCP port for command sender (default: {DEFAULT_CMD_PORT})')
    args = parser.parse_args()

    PacketLibrary.SetVehicleMACAddress(Vehicle.MRA, args.vehicle_mac)

    display(f'Starting GCS XBee on {args.xbee_port}...')
    sys.stdout = open(os.devnull, 'w')
    try:
        LaunchGCSXBee(args.xbee_port)
    except Exception as e:
        display(f'ERROR: Failed to open XBee on {args.xbee_port}: {e}')
        sys.exit(1)
    display(f'XBee connected. Vehicle MAC: {args.vehicle_mac}\n')

    threading.Thread(target=telemetry_listener, daemon=True).start()
    threading.Thread(target=command_server, args=(args.cmd_port,), daemon=True).start()

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        display('\nStopped.')


if __name__ == '__main__':
    main()
