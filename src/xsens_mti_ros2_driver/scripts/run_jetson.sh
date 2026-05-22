#!/bin/bash
cd ~/ugv-integration-2526
source install/setup.bash
cd src/xsens_mti_ros2_driver/scripts

# Start xsens in background
ros2 launch xsens_mti_ros2_driver xsens_mti_node.launch.py &
XSENS_PID=$!
sleep 8

# Get GPS coordinates
timeout 30 python3 coord_dump.py || true

# Start result listener
python3 jetson_result_listener.py

kill $XSENS_PID 2>/dev/null
