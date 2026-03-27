// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__STRUCT_H_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/ShipMotion in the package xsens_mti_ros2_driver.
typedef struct xsens_mti_ros2_driver__msg__ShipMotion
{
  std_msgs__msg__Header header;
  /// meters
  double heave_position;
  /// seconds
  double heave_period;
} xsens_mti_ros2_driver__msg__ShipMotion;

// Struct for a sequence of xsens_mti_ros2_driver__msg__ShipMotion.
typedef struct xsens_mti_ros2_driver__msg__ShipMotion__Sequence
{
  xsens_mti_ros2_driver__msg__ShipMotion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_mti_ros2_driver__msg__ShipMotion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__STRUCT_H_
