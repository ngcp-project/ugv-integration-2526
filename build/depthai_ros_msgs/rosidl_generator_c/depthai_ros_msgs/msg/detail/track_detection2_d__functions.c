// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from depthai_ros_msgs:msg/TrackDetection2D.idl
// generated code does not contain a copyright notice
#include "depthai_ros_msgs/msg/detail/track_detection2_d__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `results`
#include "vision_msgs/msg/detail/object_hypothesis_with_pose__functions.h"
// Member `bbox`
#include "vision_msgs/msg/detail/bounding_box2_d__functions.h"
// Member `tracking_id`
#include "rosidl_runtime_c/string_functions.h"

bool
depthai_ros_msgs__msg__TrackDetection2D__init(depthai_ros_msgs__msg__TrackDetection2D * msg)
{
  if (!msg) {
    return false;
  }
  // results
  if (!vision_msgs__msg__ObjectHypothesisWithPose__Sequence__init(&msg->results, 0)) {
    depthai_ros_msgs__msg__TrackDetection2D__fini(msg);
    return false;
  }
  // bbox
  if (!vision_msgs__msg__BoundingBox2D__init(&msg->bbox)) {
    depthai_ros_msgs__msg__TrackDetection2D__fini(msg);
    return false;
  }
  // is_tracking
  // tracking_id
  if (!rosidl_runtime_c__String__init(&msg->tracking_id)) {
    depthai_ros_msgs__msg__TrackDetection2D__fini(msg);
    return false;
  }
  // tracking_age
  // tracking_status
  return true;
}

void
depthai_ros_msgs__msg__TrackDetection2D__fini(depthai_ros_msgs__msg__TrackDetection2D * msg)
{
  if (!msg) {
    return;
  }
  // results
  vision_msgs__msg__ObjectHypothesisWithPose__Sequence__fini(&msg->results);
  // bbox
  vision_msgs__msg__BoundingBox2D__fini(&msg->bbox);
  // is_tracking
  // tracking_id
  rosidl_runtime_c__String__fini(&msg->tracking_id);
  // tracking_age
  // tracking_status
}

bool
depthai_ros_msgs__msg__TrackDetection2D__are_equal(const depthai_ros_msgs__msg__TrackDetection2D * lhs, const depthai_ros_msgs__msg__TrackDetection2D * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // results
  if (!vision_msgs__msg__ObjectHypothesisWithPose__Sequence__are_equal(
      &(lhs->results), &(rhs->results)))
  {
    return false;
  }
  // bbox
  if (!vision_msgs__msg__BoundingBox2D__are_equal(
      &(lhs->bbox), &(rhs->bbox)))
  {
    return false;
  }
  // is_tracking
  if (lhs->is_tracking != rhs->is_tracking) {
    return false;
  }
  // tracking_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tracking_id), &(rhs->tracking_id)))
  {
    return false;
  }
  // tracking_age
  if (lhs->tracking_age != rhs->tracking_age) {
    return false;
  }
  // tracking_status
  if (lhs->tracking_status != rhs->tracking_status) {
    return false;
  }
  return true;
}

bool
depthai_ros_msgs__msg__TrackDetection2D__copy(
  const depthai_ros_msgs__msg__TrackDetection2D * input,
  depthai_ros_msgs__msg__TrackDetection2D * output)
{
  if (!input || !output) {
    return false;
  }
  // results
  if (!vision_msgs__msg__ObjectHypothesisWithPose__Sequence__copy(
      &(input->results), &(output->results)))
  {
    return false;
  }
  // bbox
  if (!vision_msgs__msg__BoundingBox2D__copy(
      &(input->bbox), &(output->bbox)))
  {
    return false;
  }
  // is_tracking
  output->is_tracking = input->is_tracking;
  // tracking_id
  if (!rosidl_runtime_c__String__copy(
      &(input->tracking_id), &(output->tracking_id)))
  {
    return false;
  }
  // tracking_age
  output->tracking_age = input->tracking_age;
  // tracking_status
  output->tracking_status = input->tracking_status;
  return true;
}

depthai_ros_msgs__msg__TrackDetection2D *
depthai_ros_msgs__msg__TrackDetection2D__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  depthai_ros_msgs__msg__TrackDetection2D * msg = (depthai_ros_msgs__msg__TrackDetection2D *)allocator.allocate(sizeof(depthai_ros_msgs__msg__TrackDetection2D), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(depthai_ros_msgs__msg__TrackDetection2D));
  bool success = depthai_ros_msgs__msg__TrackDetection2D__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
depthai_ros_msgs__msg__TrackDetection2D__destroy(depthai_ros_msgs__msg__TrackDetection2D * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    depthai_ros_msgs__msg__TrackDetection2D__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
depthai_ros_msgs__msg__TrackDetection2D__Sequence__init(depthai_ros_msgs__msg__TrackDetection2D__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  depthai_ros_msgs__msg__TrackDetection2D * data = NULL;

  if (size) {
    data = (depthai_ros_msgs__msg__TrackDetection2D *)allocator.zero_allocate(size, sizeof(depthai_ros_msgs__msg__TrackDetection2D), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = depthai_ros_msgs__msg__TrackDetection2D__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        depthai_ros_msgs__msg__TrackDetection2D__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
depthai_ros_msgs__msg__TrackDetection2D__Sequence__fini(depthai_ros_msgs__msg__TrackDetection2D__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      depthai_ros_msgs__msg__TrackDetection2D__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

depthai_ros_msgs__msg__TrackDetection2D__Sequence *
depthai_ros_msgs__msg__TrackDetection2D__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  depthai_ros_msgs__msg__TrackDetection2D__Sequence * array = (depthai_ros_msgs__msg__TrackDetection2D__Sequence *)allocator.allocate(sizeof(depthai_ros_msgs__msg__TrackDetection2D__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = depthai_ros_msgs__msg__TrackDetection2D__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
depthai_ros_msgs__msg__TrackDetection2D__Sequence__destroy(depthai_ros_msgs__msg__TrackDetection2D__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    depthai_ros_msgs__msg__TrackDetection2D__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
depthai_ros_msgs__msg__TrackDetection2D__Sequence__are_equal(const depthai_ros_msgs__msg__TrackDetection2D__Sequence * lhs, const depthai_ros_msgs__msg__TrackDetection2D__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!depthai_ros_msgs__msg__TrackDetection2D__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
depthai_ros_msgs__msg__TrackDetection2D__Sequence__copy(
  const depthai_ros_msgs__msg__TrackDetection2D__Sequence * input,
  depthai_ros_msgs__msg__TrackDetection2D__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(depthai_ros_msgs__msg__TrackDetection2D);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    depthai_ros_msgs__msg__TrackDetection2D * data =
      (depthai_ros_msgs__msg__TrackDetection2D *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!depthai_ros_msgs__msg__TrackDetection2D__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          depthai_ros_msgs__msg__TrackDetection2D__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!depthai_ros_msgs__msg__TrackDetection2D__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
