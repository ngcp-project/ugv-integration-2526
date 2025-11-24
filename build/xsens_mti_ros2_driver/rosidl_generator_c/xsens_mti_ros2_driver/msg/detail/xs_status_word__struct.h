// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__STRUCT_H_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/XsStatusWord in the package xsens_mti_ros2_driver.
/**
  * Define the custom XsStatusWord message
 */
typedef struct xsens_mti_ros2_driver__msg__XsStatusWord
{
  bool selftest;
  bool filter_valid;
  bool gnss_fix;
  /// 0: not running, 2: aborted, 3:running
  uint8_t no_rotation_update_status;
  bool representative_motion;
  bool clock_bias_estimation;
  /// bool reserved1
  bool clipflag_acc_x;
  bool clipflag_acc_y;
  bool clipflag_acc_z;
  bool clipflag_gyr_x;
  bool clipflag_gyr_y;
  bool clipflag_gyr_z;
  bool clipflag_mag_x;
  bool clipflag_mag_y;
  bool clipflag_mag_z;
  /// uint8 reserved2
  bool clipping_indication;
  /// bool reserved3
  bool syncin_marker;
  bool syncout_marker;
  /// 0: Without GNSS, 1: Coasting, 3: With GNSS
  uint8_t filter_mode;
  bool have_gnss_time_pulse;
  /// 0: No RTK, 1: RTK Floating, 2: RTK Fix
  uint8_t rtk_status;
} xsens_mti_ros2_driver__msg__XsStatusWord;

// Struct for a sequence of xsens_mti_ros2_driver__msg__XsStatusWord.
typedef struct xsens_mti_ros2_driver__msg__XsStatusWord__Sequence
{
  xsens_mti_ros2_driver__msg__XsStatusWord * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} xsens_mti_ros2_driver__msg__XsStatusWord__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__STRUCT_H_
