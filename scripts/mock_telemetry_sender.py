#!/usr/bin/env python3
"""Send mock telemetry UDP packets to the GCS for testing."""
import argparse
import socket
import struct
import time

PACKET_FORMAT = '<xx fffff 12x dd'


def main():
    parser = argparse.ArgumentParser(description='Send mock telemetry to GCS')
    parser.add_argument('--gcs-ip', required=True, help='GCS machine IP address')
    parser.add_argument('--gcs-port', type=int, default=5005)
    parser.add_argument('--interval', type=float, default=1.0, help='Seconds between packets')
    args = parser.parse_args()

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print(f'Sending mock telemetry to {args.gcs_ip}:{args.gcs_port} every {args.interval}s')
    print('Press Ctrl+C to stop\n')

    counter = 0
    try:
        while True:
            speed = 5.0 + (counter % 10)
            pitch = 1.5
            yaw = 90.0 + (counter % 360)
            roll = -0.3
            altitude = 150.0
            latitude = 33.882527 + counter * 0.00001
            longitude = -117.882727 + counter * 0.00001

            packet = struct.pack(PACKET_FORMAT, speed, pitch, yaw, roll, altitude, latitude, longitude)
            sock.sendto(packet, (args.gcs_ip, args.gcs_port))

            print(
                f'[{counter}] Speed: {speed:.1f} ft/s | '
                f'Yaw: {yaw:.1f}° | '
                f'Lat: {latitude:.6f} | '
                f'Lon: {longitude:.6f}'
            )

            counter += 1
            time.sleep(args.interval)
    except KeyboardInterrupt:
        print('\nStopped.')
    finally:
        sock.close()


if __name__ == '__main__':
    main()
