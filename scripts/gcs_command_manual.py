#!/usr/bin/env python3
"""GCS manual command sender — interactive menu to send one command at a time.

Usage:
    python scripts/gcs_command_manual.py --xbee-port COM3 --vehicle-mac 0013A20042839F3E
"""
import argparse
import os
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

out = sys.stderr

reply_event = threading.Event()
last_reply = None


def telemetry_listener():
    global last_reply
    while True:
        try:
            telem = ReceiveTelemetry()
            last_reply = telem
            reply_event.set()
            print(
                f'  <- REPLY  '
                f'CmdID={telem.CommandID}  PktID={telem.PacketID}  '
                f'Speed={telem.Speed:.3f}  Yaw={telem.Yaw:.3f}  '
                f'Pos=({telem.CurrentPositionX:.6f}, {telem.CurrentPositionY:.6f})  '
                f'Status={telem.VehicleStatus}  '
                f'MsgFlag={telem.MessageFlag}',
                file=out,
            )
        except Exception as e:
            print(f'  <- REPLY ERROR: {e}', file=out)
            time.sleep(1)


MENU = """
Commands:
  1 - Heartbeat (Connected)
  2 - Heartbeat (Disconnected)
  3 - EmergencyStop (ACTIVATE)
  4 - EmergencyStop (RELEASE)
  5 - AddZone (KeepIn)
  6 - AddZone (KeepOut)
  7 - PatientLocation
  q - Quit
> """


def send_and_wait(cmd, label, count):
    reply_event.clear()
    cmd.Vehicle = Vehicle.MRA
    SendCommand(cmd, Vehicle.MRA)
    print(f'[{count}] SEND -> {label}', file=out, end='')

    if reply_event.wait(timeout=3.0):
        print('', file=out)
    else:
        print(' — NO REPLY (error, try again)', file=out)


def main():
    parser = argparse.ArgumentParser(description='Manual GCS command sender')
    parser.add_argument('--xbee-port', required=True, help='Serial port for GCS XBee (e.g. COM3)')
    parser.add_argument('--vehicle-mac', default='0013A20042839F3E',
                        help='64-bit MAC of the vehicle XBee')
    args = parser.parse_args()

    PacketLibrary.SetVehicleMACAddress(Vehicle.MRA, args.vehicle_mac)

    print(f'Starting GCS XBee on {args.xbee_port}...', file=out)

    sys.stdout = open(os.devnull, 'w')
    LaunchGCSXBee(args.xbee_port)

    print(f'Connected to vehicle {args.vehicle_mac}', file=out)

    listener = threading.Thread(target=telemetry_listener, daemon=True)
    listener.start()

    count = 0
    print(MENU, file=out, end='')

    try:
        while True:
            choice = input('')
            cmd = None
            label = ''

            if choice == '1':
                cmd = Heartbeat(ConnectionStatus.Connected)
                label = 'Heartbeat (Connected)'
            elif choice == '2':
                cmd = Heartbeat(ConnectionStatus.Disconnected)
                label = 'Heartbeat (Disconnected)'
            elif choice == '3':
                cmd = EmergencyStop(0)
                label = 'EmergencyStop (ACTIVATE)'
            elif choice == '4':
                cmd = EmergencyStop(1)
                label = 'EmergencyStop (RELEASE)'
            elif choice == '5':
                coords = [(33.8830, -117.8830), (33.8820, -117.8820),
                          (33.8815, -117.8835), (33.8825, -117.8840)]
                cmd = AddZone(ZoneType.KeepIn, coords)
                label = 'AddZone (KeepIn, 4 coords)'
            elif choice == '6':
                coords = [(33.8830, -117.8830), (33.8820, -117.8820),
                          (33.8815, -117.8835), (33.8825, -117.8840)]
                cmd = AddZone(ZoneType.KeepOut, coords)
                label = 'AddZone (KeepOut, 4 coords)'
            elif choice == '7':
                lat, lon = 33.8825, -117.8827
                cmd = PatientLocation((lat, lon))
                label = f'PatientLocation (lat={lat:.6f}, lon={lon:.6f})'
            elif choice in ('q', 'Q'):
                break
            else:
                print(f'Unknown option: {choice}', file=out)
                print(MENU, file=out, end='')
                continue

            if cmd:
                count += 1
                send_and_wait(cmd, label, count)
                print('> ', file=out, end='')

    except (KeyboardInterrupt, EOFError):
        pass

    print('\nStopped.', file=out)


if __name__ == '__main__':
    main()
