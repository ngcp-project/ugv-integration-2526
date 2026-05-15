### GCS Side
  python scripts/gcs_command_manual.py --xbee-port COM3

  python scripts/gcs_command_sender.py


### Jetson Side
  ros2 launch ugv_comms ugv_all.launch.py xbee_port:=/dev/ttyUSB0

