#!/bin/bash
cd ~/ugv-integration-2526
source /opt/ros/humble/setup.bash
source install/setup.bash
cd src/xsens_mti_ros2_driver/scripts

# Start the full ROS 2 stack (xsens driver + nav subscriber + ntrip + telemetry + teleop + xbee)
ros2 launch ugv_comms ugv_full.launch.py &
LAUNCH_PID=$!
sleep 12

# Capture initial GPS coordinates for ntrip
timeout 30 python3 coord_dump.py || true

# Start result listener (foreground; keeps service alive)
python3 jetson_result_listener.py

kill $LAUNCH_PID 2>/dev/null
