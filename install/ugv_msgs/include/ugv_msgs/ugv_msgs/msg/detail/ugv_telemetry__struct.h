// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ugv_msgs:msg/UGVTelemetry.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__STRUCT_H_
#define UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/UGVTelemetry in the package ugv_msgs.
typedef struct ugv_msgs__msg__UGVTelemetry
{
  float speed_fps;
  float pitch_deg;
  float yaw_deg;
  float roll_deg;
  float altitude_ft;
  double latitude;
  double longitude;
} ugv_msgs__msg__UGVTelemetry;

// Struct for a sequence of ugv_msgs__msg__UGVTelemetry.
typedef struct ugv_msgs__msg__UGVTelemetry__Sequence
{
  ugv_msgs__msg__UGVTelemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ugv_msgs__msg__UGVTelemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__STRUCT_H_
