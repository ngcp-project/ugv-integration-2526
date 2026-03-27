// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from depthai_ros_msgs:msg/TrackDetection2D.idl
// generated code does not contain a copyright notice

#ifndef DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__STRUCT_H_
#define DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'results'
#include "vision_msgs/msg/detail/object_hypothesis_with_pose__struct.h"
// Member 'bbox'
#include "vision_msgs/msg/detail/bounding_box2_d__struct.h"
// Member 'tracking_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TrackDetection2D in the package depthai_ros_msgs.
typedef struct depthai_ros_msgs__msg__TrackDetection2D
{
  /// Class probabilities
  vision_msgs__msg__ObjectHypothesisWithPose__Sequence results;
  /// 2D bounding box surrounding the object.
  vision_msgs__msg__BoundingBox2D bbox;
  /// If true, this message contains object tracking information.
  bool is_tracking;
  /// ID used for consistency across multiple detection messages. This value will
  /// likely differ from the id field set in each individual ObjectHypothesis.
  /// If you set this field, be sure to also set is_tracking to True.
  rosidl_runtime_c__String tracking_id;
  /// Age: number of frames the object is being tracked
  int32_t tracking_age;
  /// Status of the tracking:
  /// 0 = NEW -> the object is newly added.
  /// 1 = TRACKED -> the object is being tracked.
  /// 2 = LOST -> the object gets lost now. The object can be tracked again automatically (long term tracking)
  ///     or by specifying detected object manually (short term and zero term tracking).
  /// 3 = REMOVED -> the object is removed.
  int32_t tracking_status;
} depthai_ros_msgs__msg__TrackDetection2D;

// Struct for a sequence of depthai_ros_msgs__msg__TrackDetection2D.
typedef struct depthai_ros_msgs__msg__TrackDetection2D__Sequence
{
  depthai_ros_msgs__msg__TrackDetection2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} depthai_ros_msgs__msg__TrackDetection2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEPTHAI_ROS_MSGS__MSG__DETAIL__TRACK_DETECTION2_D__STRUCT_H_
