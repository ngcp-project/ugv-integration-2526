#!/usr/bin/env python3
"""GCS display + command input.

Can be used standalone (type commands directly) or with gcs_command_sender.py
in a second terminal for a split display/input setup.

Usage:
    python scripts/gcs_command_manual.py
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
from port_detect import find_xbee_port

DEFAULT_CMD_PORT = 5556

out = sys.stderr

_count = 0
_count_lock = threading.Lock()

MENU = """
Commands:
  1 - Heartbeat (Connected)
  2 - Heartbeat (Disconnected)
  3 - EmergencyStop (ACTIVATE)
  4 - EmergencyStop (RELEASE)
  5 - AddZone (KeepIn)
  6 - AddZone (KeepOut)
  7 - PatientLocation (uses Jetson GPS position)
  8 - AddZone from JSON
  q - Quit
> """


def display(msg):
    print(msg, file=out, flush=True)


def telemetry_listener():
    while True:
        try:
            telem = ReceiveTelemetry()
            line = (
                f'  <- REPLY  '
                f'CmdID={telem.CommandID}  PktID={telem.PacketID}  '
                f'Speed={telem.Speed:.3f}  Yaw={telem.Yaw:.3f}  '
                f'Pos=({telem.CurrentPositionX:.6f}, {telem.CurrentPositionY:.6f})  '
                f'Status={telem.VehicleStatus}  '
                f'MsgFlag={telem.MessageFlag}'
            )
            display(line)
            if telem.MessageFlag == 2:
                display(
                    f'  ** PATIENT LOCATION: '
                    f'lat={telem.MessageLat:.6f}, lon={telem.MessageLon:.6f}'
                )
        except Exception as e:
            display(f'  <- REPLY ERROR: {e}')
            time.sleep(1)


def next_seq():
    global _count
    with _count_lock:
        _count += 1
        return _count


def execute_command(request):
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

    seq = next_seq()
    display(f'[{seq}] SENT -> {label}')
    if cmd_id in (5, 6):
        for i, c in enumerate(request.get('coordinates', [])):
            display(f'       coord {i+1}: ({c[0]:.6f}, {c[1]:.6f})')

    return {'ok': True, 'label': label}


# ── Direct keyboard input (main thread) ──────────────────────────────

def prompt_coordinates():
    coords = []
    print('Enter 3-6 coordinates as "lat,lon". Type "d" when done, "c" to cancel.', file=out)
    while len(coords) < 6:
        print(f'  Coord {len(coords)+1}> ', file=out, end='', flush=True)
        try:
            line = input('').strip()
        except (KeyboardInterrupt, EOFError):
            return None
        if line.lower() == 'c':
            return None
        if line.lower() == 'd':
            if len(coords) < 3:
                print(f'  Need at least 3 ({len(coords)} so far).', file=out)
                continue
            break
        try:
            parts = line.split(',')
            if len(parts) != 2:
                raise ValueError
            lat, lon = float(parts[0].strip()), float(parts[1].strip())
            coords.append([lat, lon])
            print(f'  Added ({lat:.6f}, {lon:.6f})', file=out)
        except ValueError:
            print('  Invalid. Use: lat,lon  (e.g. 33.8830,-117.8830)', file=out)
    if len(coords) == 6:
        print('  Maximum 6 coordinates reached.', file=out)
    return coords if len(coords) >= 3 else None


def parse_zone_json(raw):
    """Parse a JSON zone string or @filepath into (cmd_id, coordinates).

    JSON format:
        {"type": "keep_in"|"keep_out", "coords": [[lat, lon, alt], ...]}
    Alt is carried in the JSON but not sent in the packet (lat/lon only).
    """
    if raw.startswith('@'):
        path = raw[1:].strip()
        with open(path, 'r') as f:
            raw = f.read()
    data = json.loads(raw)
    zone_type = data.get('type', '').lower().replace('-', '_').replace(' ', '_')
    if zone_type == 'keep_in':
        cmd_id = 5
    elif zone_type == 'keep_out':
        cmd_id = 6
    else:
        raise ValueError(f'type must be "keep_in" or "keep_out", got "{data.get("type")}"')
    raw_coords = data.get('coords', [])
    if not (3 <= len(raw_coords) <= 6):
        raise ValueError(f'Need 3-6 coordinates, got {len(raw_coords)}')
    coords = []
    for c in raw_coords:
        if len(c) < 2:
            raise ValueError(f'Each coord needs at least [lat, lon], got {c}')
        coords.append([float(c[0]), float(c[1])])
    return cmd_id, coords


def keyboard_loop():
    print(MENU, file=out, end='')
    while True:
        try:
            choice = input('').strip()
        except (KeyboardInterrupt, EOFError):
            break

        request = None

        if choice == '1':
            request = {'cmd': 1}
        elif choice == '2':
            request = {'cmd': 2}
        elif choice == '3':
            request = {'cmd': 3}
        elif choice == '4':
            request = {'cmd': 4}
        elif choice in ('5', '6'):
            coords = prompt_coordinates()
            if coords is None:
                print(MENU, file=out, end='')
                continue
            request = {'cmd': int(choice), 'coordinates': coords}
        elif choice == '7':
            request = {'cmd': 7}
        elif choice == '8':
            print('  Paste JSON or @filepath:', file=out)
            print('  Format: {"type": "keep_in", "coords": [[lat,lon,alt], ...]}', file=out)
            print('  JSON> ', file=out, end='', flush=True)
            try:
                raw = input('').strip()
            except (KeyboardInterrupt, EOFError):
                print(MENU, file=out, end='')
                continue
            if not raw:
                print(MENU, file=out, end='')
                continue
            try:
                cmd_id, coords = parse_zone_json(raw)
                request = {'cmd': cmd_id, 'coordinates': coords}
            except Exception as e:
                print(f'  Error: {e}', file=out)
                print(MENU, file=out, end='')
                continue
        elif choice in ('q', 'Q'):
            break
        else:
            print(f'Unknown option: {choice}', file=out)
            print(MENU, file=out, end='')
            continue

        resp = execute_command(request)
        if not resp.get('ok'):
            print(f'  Error: {resp.get("error")}', file=out)
        print('> ', file=out, end='', flush=True)

    display('\nStopped.')


# ── TCP server for gcs_command_sender.py (background) ────────────────

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
    try:
        srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        srv.bind(('127.0.0.1', port))
        srv.listen(1)
        display(f'Also listening for gcs_command_sender.py on port {port}\n')
    except Exception as e:
        display(f'TCP server failed to start: {e} (keyboard input still works)\n')
        return

    while True:
        conn, addr = srv.accept()
        display('Command sender connected.')
        threading.Thread(target=handle_client, args=(conn,), daemon=True).start()


# ── Main ─────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description='GCS display + command input')
    parser.add_argument('--xbee-port', default='auto',
                        help='Serial port for GCS XBee (e.g. COM3). Default: auto-detect')
    parser.add_argument('--vehicle-mac', default='0013A20042839F3E',
                        help='64-bit MAC of the vehicle XBee')
    parser.add_argument('--cmd-port', type=int, default=DEFAULT_CMD_PORT,
                        help=f'TCP port for command sender (default: {DEFAULT_CMD_PORT})')
    args = parser.parse_args()

    xbee_port = args.xbee_port
    if xbee_port == 'auto':
        display('Auto-detecting XBee port...')
        xbee_port = find_xbee_port()
        if not xbee_port:
            print('ERROR: Could not auto-detect XBee port. Use --xbee-port to specify.', file=out)
            sys.exit(1)

    PacketLibrary.SetVehicleMACAddress(Vehicle.MRA, args.vehicle_mac)

    display(f'Starting GCS XBee on {xbee_port}...')
    sys.stdout = open(os.devnull, 'w')
    try:
        LaunchGCSXBee(xbee_port)
    except Exception as e:
        print(f'ERROR: Failed to open XBee on {xbee_port}: {e}', file=out)
        sys.exit(1)
    display(f'XBee connected. Vehicle MAC: {args.vehicle_mac}')

    threading.Thread(target=telemetry_listener, daemon=True).start()
    threading.Thread(target=command_server, args=(args.cmd_port,), daemon=True).start()

    keyboard_loop()


if __name__ == '__main__':
    main()
