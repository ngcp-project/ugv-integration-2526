// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "xsens_mti_ros2_driver/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace xsens_mti_ros2_driver
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
cdr_serialize(
  const xsens_mti_ros2_driver::msg::XsStatusWord & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_mti_ros2_driver::msg::XsStatusWord & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
get_serialized_size(
  const xsens_mti_ros2_driver::msg::XsStatusWord & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
max_serialized_size_XsStatusWord(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xsens_mti_ros2_driver

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_mti_ros2_driver, msg, XsStatusWord)();

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
