#!/bin/bash
cd ~/ugv-integration-2526/src/xsens_mti_ros2_driver/scripts

# Kill anything left on port 5101 from a previous run
sudo fuser -k 5101/tcp 2>/dev/null

# Give the Pi a moment to be ready
sleep 2

python3 jetson_result_listener.py
