
# How to run the whole thing

## Terminal 1 — GCS:
python scripts/gcs_command_manual.py --xbee-port COM3
This opens the XBee link and shows the menu + telemetry replies.

## Terminal 2 (optional):
python scripts/gcs_command_sender.py

## Jetson side:
ros2 launch ugv_comms ugv_all.launch.py xbee_port:=/dev/ttyUSB0

To send a zone via JSON (from either Terminal 1 or 2):
> 8
  Paste JSON or @filepath:
  Format: {"type": "keep_in", "coords": [[lat,lon,alt], ...]}
  JSON> {"type": "keep_out", "coords":
[[33.883,-117.883,50],[33.882,-117.882,50],[33.8815,-117.8835,50]]}

Or save that JSON to a file and do:
  JSON> @C:\YourUserDirectory\zones\test_zone.json