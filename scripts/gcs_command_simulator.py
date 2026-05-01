#!/usr/bin/env python3
"""GCS command simulator — sends random commands via XBee every 5 seconds
and prints any telemetry replies received from the Jetson.

Usage:
    python scripts/gcs_command_simulator.py --xbee-port COM3 --vehicle-mac 0013A20042839F3E
"""
import argparse
import os
import random
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

# Send all our output to stderr so we can mute the XBee library's stdout spam
out = sys.stderr


def make_heartbeat():
    status = random.choice(list(ConnectionStatus))
    cmd = Heartbeat(status)
    label = f'Heartbeat (status={status.name})'
    return cmd, label


def make_emergency_stop():
    stop = random.choice([0, 1])
    cmd = EmergencyStop(stop)
    action = 'ACTIVATE' if stop == 0 else 'RELEASE'
    label = f'EmergencyStop ({action})'
    return cmd, label


def make_add_zone():
    zone_type = random.choice(list(ZoneType))
    num_coords = random.randint(3, 4)
    base_lat, base_lon = 33.8825, -117.8827
    coords = [
        (base_lat + random.uniform(-0.001, 0.001),
         base_lon + random.uniform(-0.001, 0.001))
        for _ in range(num_coords)
    ]
    cmd = AddZone(zone_type, coords)
    label = f'AddZone (type={zone_type.name}, {num_coords} coords)'
    return cmd, label


def make_patient_location():
    lat = 33.8825 + random.uniform(-0.005, 0.005)
    lon = -117.8827 + random.uniform(-0.005, 0.005)
    cmd = PatientLocation((lat, lon))
    label = f'PatientLocation (lat={lat:.6f}, lon={lon:.6f})'
    return cmd, label


COMMAND_BUILDERS = [
    make_heartbeat,
    make_emergency_stop,
    make_add_zone,
    make_patient_location,
]


def telemetry_listener():
    """Background thread: prints telemetry replies from the Jetson."""
    while True:
        try:
            telem = ReceiveTelemetry()
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


def main():
    parser = argparse.ArgumentParser(description='Simulate GCS commands over XBee')
    parser.add_argument('--xbee-port', required=True, help='Serial port for GCS XBee (e.g. COM3)')
    parser.add_argument('--vehicle-mac', default='0013A20042839F3E',
                        help='64-bit MAC of the vehicle XBee')
    parser.add_argument('--interval', type=float, default=5.0,
                        help='Seconds between commands (default: 5)')
    args = parser.parse_args()

    PacketLibrary.SetVehicleMACAddress(Vehicle.MRA, args.vehicle_mac)

    print(f'Starting GCS XBee on {args.xbee_port}...', file=out)

    # Mute all stdout from XBee library background threads
    sys.stdout = open(os.devnull, 'w')

    LaunchGCSXBee(args.xbee_port)

    print(f'Connected. Sending random commands every {args.interval}s to vehicle {args.vehicle_mac}', file=out)
    print('Press Ctrl+C to stop\n', file=out)

    listener = threading.Thread(target=telemetry_listener, daemon=True)
    listener.start()

    count = 0
    try:
        while True:
            builder = random.choice(COMMAND_BUILDERS)
            cmd, label = builder()
            cmd.Vehicle = Vehicle.MRA
            count += 1

            print(f'[{count}] SEND -> {label}', file=out)
            SendCommand(cmd, Vehicle.MRA)

            time.sleep(args.interval)
    except KeyboardInterrupt:
        print('\nStopped.', file=out)


if __name__ == '__main__':
    main()
