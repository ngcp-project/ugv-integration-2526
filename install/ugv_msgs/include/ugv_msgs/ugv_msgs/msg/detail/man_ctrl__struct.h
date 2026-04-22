// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__MAN_CTRL__STRUCT_H_
#define UGV_MSGS__MSG__DETAIL__MAN_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ManCtrl in the package ugv_msgs.
typedef struct ugv_msgs__msg__ManCtrl
{
  bool auto_en;
  float linear_vel;
  float steer_cmd;
  float arm_cmd[2];
} ugv_msgs__msg__ManCtrl;

// Struct for a sequence of ugv_msgs__msg__ManCtrl.
typedef struct ugv_msgs__msg__ManCtrl__Sequence
{
  ugv_msgs__msg__ManCtrl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ugv_msgs__msg__ManCtrl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UGV_MSGS__MSG__DETAIL__MAN_CTRL__STRUCT_H_
