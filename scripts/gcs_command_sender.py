#!/usr/bin/env python3
"""GCS command sender — interactive menu to send commands to the Jetson.

Start gcs_command_manual.py first (it owns the XBee link), then run this in
a second terminal.

Usage:
    python scripts/gcs_command_sender.py
    python scripts/gcs_command_sender.py --port 5556
"""
import argparse
import json
import socket
import sys

DEFAULT_PORT = 5556

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


def connect(port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('127.0.0.1', port))
    return sock


def send_request(sock, request):
    sock.sendall((json.dumps(request) + '\n').encode('utf-8'))
    buf = ''
    while '\n' not in buf:
        data = sock.recv(4096)
        if not data:
            raise ConnectionError('Display disconnected')
        buf += data.decode('utf-8')
    return json.loads(buf.split('\n', 1)[0])


def prompt_coordinates():
    coords = []
    print('Enter 3 to 6 coordinates as "lat,lon" (e.g. 33.8830,-117.8830).')
    print('Type "d" when done, "c" to cancel.')
    while len(coords) < 6:
        try:
            line = input(f'  Coord {len(coords)+1}> ').strip()
        except (KeyboardInterrupt, EOFError):
            print('\nCancelled.')
            return None
        if line.lower() == 'c':
            print('Cancelled.')
            return None
        if line.lower() == 'd':
            if len(coords) < 3:
                print(f'  Need at least 3 coordinates ({len(coords)} so far).')
                continue
            break
        try:
            parts = line.split(',')
            if len(parts) != 2:
                raise ValueError
            lat, lon = float(parts[0].strip()), float(parts[1].strip())
            coords.append([lat, lon])
            print(f'  Added ({lat:.6f}, {lon:.6f})')
        except ValueError:
            print('  Invalid format. Use: lat,lon  (e.g. 33.8830,-117.8830)')

    if len(coords) == 6:
        print('  Maximum 6 coordinates reached.')

    return coords if len(coords) >= 3 else None


def prompt_patient_location():
    print('Enter patient location as "lat,lon" (or "c" to cancel):')
    while True:
        try:
            line = input('  > ').strip()
        except (KeyboardInterrupt, EOFError):
            print('\nCancelled.')
            return None, None
        if line.lower() == 'c':
            print('Cancelled.')
            return None, None
        try:
            parts = line.split(',')
            if len(parts) != 2:
                raise ValueError
            return float(parts[0].strip()), float(parts[1].strip())
        except ValueError:
            print('  Invalid format. Use: lat,lon  (e.g. 33.8825,-117.8827)')


def main():
    parser = argparse.ArgumentParser(description='GCS command sender')
    parser.add_argument('--port', type=int, default=DEFAULT_PORT,
                        help=f'TCP port of GCS display (default: {DEFAULT_PORT})')
    args = parser.parse_args()

    print(f'Connecting to GCS display on port {args.port}...')
    try:
        sock = connect(args.port)
    except ConnectionRefusedError:
        print('ERROR: Cannot connect. Is gcs_command_manual.py running?',
              file=sys.stderr)
        sys.exit(1)

    print('Connected.')
    print(MENU, end='')

    try:
        while True:
            choice = input('').strip()
            request = None

            if choice == '1':
                request = {'cmd': 1}
            elif choice == '2':
                request = {'cmd': 2}
            elif choice == '3':
                request = {'cmd': 3}
            elif choice == '4':
                request = {'cmd': 4}
            elif choice == '5':
                coords = prompt_coordinates()
                if coords is None:
                    print(MENU, end='')
                    continue
                request = {'cmd': 5, 'coordinates': coords}
            elif choice == '6':
                coords = prompt_coordinates()
                if coords is None:
                    print(MENU, end='')
                    continue
                request = {'cmd': 6, 'coordinates': coords}
            elif choice == '7':
                lat, lon = prompt_patient_location()
                if lat is None:
                    print(MENU, end='')
                    continue
                request = {'cmd': 7, 'lat': lat, 'lon': lon}
            elif choice in ('q', 'Q'):
                break
            else:
                print(f'Unknown option: {choice}')
                print(MENU, end='')
                continue

            try:
                resp = send_request(sock, request)
                if resp.get('ok'):
                    print(f'  Sent: {resp.get("label")}')
                else:
                    print(f'  Error: {resp.get("error")}')
            except Exception as e:
                print(f'  Send failed: {e}')
                break

            print('> ', end='')

    except (KeyboardInterrupt, EOFError):
        pass

    sock.close()
    print('\nDisconnected.')


if __name__ == '__main__':
    main()
