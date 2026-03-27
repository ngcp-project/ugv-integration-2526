// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from depthai_ros_msgs:msg/TrackDetection2DArray.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D_ARRAY__STRUCT_H_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D_ARRAY__STRUCT_H_

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
// Member 'detections'
#include "depthai_ros_msgs/msg/detail/track_detection2_d__struct.h"

/// Struct defined in msg/TrackDetection2DArray in the package depthai_ros_msgs.
/**
  * A list of 2D tracklets, for a multi-object 2D tracker.
 */
typedef struct depthai_ros_msgs__msg__TrackDetection2DArray
{
  std_msgs__msg__Header header;
  /// A list of the tracking proposals.
  depthai_ros_msgs__msg__TrackDetection2D__Sequence detections;
} depthai_ros_msgs__msg__TrackDetection2DArray;

// Struct for a sequence of depthai_ros_msgs__msg__TrackDetection2DArray.
typedef struct depthai_ros_msgs__msg__TrackDetection2DArray__Sequence
{
  depthai_ros_msgs__msg__TrackDetection2DArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} depthai_ros_msgs__msg__TrackDetection2DArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D_ARRAY__STRUCT_H_
