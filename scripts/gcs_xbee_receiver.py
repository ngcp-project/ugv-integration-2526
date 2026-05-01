#!/usr/bin/env python3
"""GCS-side XBee receiver — prints telemetry (including joystick data) from the Jetson.

Usage:
    python scripts/gcs_xbee_receiver.py --xbee-port COM5 --vehicle-mac 0013A20042839F3E
"""
import argparse
import os
import sys

repo_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(repo_root, 'lib', 'gcs-infrastructure', 'Application'))
sys.path.insert(0, os.path.join(repo_root, 'lib', 'gcs-packet', 'Packet'))

from Infrastructure.InfrastructureInterface import LaunchGCSXBee, ReceiveTelemetry
from PacketLibrary.PacketLibrary import PacketLibrary
from Enum.Vehicle import Vehicle


def main():
    parser = argparse.ArgumentParser(description='Receive XBee telemetry on GCS')
    parser.add_argument('--xbee-port', required=True, help='Serial port for GCS XBee (e.g. COM5)')
    parser.add_argument('--vehicle-mac', default='0013A20042839F3E',
                        help='64-bit MAC of the vehicle XBee')
    args = parser.parse_args()

    PacketLibrary.SetVehicleMACAddress(Vehicle.MRA, args.vehicle_mac)

    print(f'Starting GCS XBee on {args.xbee_port}...')
    LaunchGCSXBee(args.xbee_port)
    print(f'Listening for telemetry from vehicle {args.vehicle_mac}')
    print('Press Ctrl+C to stop\n')

    count = 0
    try:
        while True:
            telem = ReceiveTelemetry()
            count += 1
            print(
                f'[{count}] '
                f'Vel={telem.Speed:.3f}  '
                f'Steer={telem.Yaw:.3f}  '
                f'Arm0={telem.BatteryLife:.1f}  '
                f'Arm1={telem.LastUpdated}  |  '
                f'Pitch={telem.Pitch:.2f}  '
                f'Roll={telem.Roll:.2f}  '
                f'Alt={telem.Altitude:.2f}  '
                f'Pos=({telem.CurrentPositionX:.6f}, {telem.CurrentPositionY:.6f})'
            )
    except KeyboardInterrupt:
        print('\nStopped.')


if __name__ == '__main__':
    main()
