
# How to run the whole thing

## Terminal 1 — GCS:
python scripts/gcs_command_manual.py

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

  
  ## Override if auto-detect picks wrong:
  python scripts/gcs_command_manual.py --xbee-port COM3
  ros2 launch ugv_comms ugv_all.launch.py xbee_port:=/dev/ttyUSB0
  xsens_port:=/dev/ttyUSB1

  Debug what ports are visible:
  python scripts/port_detect.py

✻ Crunched for 5m 19s