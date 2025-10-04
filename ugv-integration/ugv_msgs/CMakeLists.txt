cmake_minimum_required(VERSION 3.8)
project(ugv_msgs)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ManCtrl.msg"
  # "msg/AutoCtrl.msg"   # add if you have it
  # DEPENDENCIES std_msgs # add if your .msg uses std_msgs types
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()

