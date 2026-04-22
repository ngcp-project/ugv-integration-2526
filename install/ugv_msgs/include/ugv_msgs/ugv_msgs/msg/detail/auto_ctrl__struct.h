// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ugv_msgs:msg/AutoCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__AUTO_CTRL__STRUCT_H_
#define UGV_MSGS__MSG__DETAIL__AUTO_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AutoCtrl in the package ugv_msgs.
typedef struct ugv_msgs__msg__AutoCtrl
{
  bool auto_en;
  float heading_error;
} ugv_msgs__msg__AutoCtrl;

// Struct for a sequence of ugv_msgs__msg__AutoCtrl.
typedef struct ugv_msgs__msg__AutoCtrl__Sequence
{
  ugv_msgs__msg__AutoCtrl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ugv_msgs__msg__AutoCtrl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UGV_MSGS__MSG__DETAIL__AUTO_CTRL__STRUCT_H_
