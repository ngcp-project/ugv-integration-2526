// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice
#include "xsens_mti_ros2_driver/msg/detail/ship_motion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
xsens_mti_ros2_driver__msg__ShipMotion__init(xsens_mti_ros2_driver__msg__ShipMotion * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    xsens_mti_ros2_driver__msg__ShipMotion__fini(msg);
    return false;
  }
  // heave_position
  // heave_period
  return true;
}

void
xsens_mti_ros2_driver__msg__ShipMotion__fini(xsens_mti_ros2_driver__msg__ShipMotion * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // heave_position
  // heave_period
}

bool
xsens_mti_ros2_driver__msg__ShipMotion__are_equal(const xsens_mti_ros2_driver__msg__ShipMotion * lhs, const xsens_mti_ros2_driver__msg__ShipMotion * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // heave_position
  if (lhs->heave_position != rhs->heave_position) {
    return false;
  }
  // heave_period
  if (lhs->heave_period != rhs->heave_period) {
    return false;
  }
  return true;
}

bool
xsens_mti_ros2_driver__msg__ShipMotion__copy(
  const xsens_mti_ros2_driver__msg__ShipMotion * input,
  xsens_mti_ros2_driver__msg__ShipMotion * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // heave_position
  output->heave_position = input->heave_position;
  // heave_period
  output->heave_period = input->heave_period;
  return true;
}

xsens_mti_ros2_driver__msg__ShipMotion *
xsens_mti_ros2_driver__msg__ShipMotion__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsens_mti_ros2_driver__msg__ShipMotion * msg = (xsens_mti_ros2_driver__msg__ShipMotion *)allocator.allocate(sizeof(xsens_mti_ros2_driver__msg__ShipMotion), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_mti_ros2_driver__msg__ShipMotion));
  bool success = xsens_mti_ros2_driver__msg__ShipMotion__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xsens_mti_ros2_driver__msg__ShipMotion__destroy(xsens_mti_ros2_driver__msg__ShipMotion * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xsens_mti_ros2_driver__msg__ShipMotion__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xsens_mti_ros2_driver__msg__ShipMotion__Sequence__init(xsens_mti_ros2_driver__msg__ShipMotion__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsens_mti_ros2_driver__msg__ShipMotion * data = NULL;

  if (size) {
    data = (xsens_mti_ros2_driver__msg__ShipMotion *)allocator.zero_allocate(size, sizeof(xsens_mti_ros2_driver__msg__ShipMotion), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_mti_ros2_driver__msg__ShipMotion__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_mti_ros2_driver__msg__ShipMotion__fini(&data[i - 1]);
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
xsens_mti_ros2_driver__msg__ShipMotion__Sequence__fini(xsens_mti_ros2_driver__msg__ShipMotion__Sequence * array)
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
      xsens_mti_ros2_driver__msg__ShipMotion__fini(&array->data[i]);
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

xsens_mti_ros2_driver__msg__ShipMotion__Sequence *
xsens_mti_ros2_driver__msg__ShipMotion__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsens_mti_ros2_driver__msg__ShipMotion__Sequence * array = (xsens_mti_ros2_driver__msg__ShipMotion__Sequence *)allocator.allocate(sizeof(xsens_mti_ros2_driver__msg__ShipMotion__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xsens_mti_ros2_driver__msg__ShipMotion__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xsens_mti_ros2_driver__msg__ShipMotion__Sequence__destroy(xsens_mti_ros2_driver__msg__ShipMotion__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xsens_mti_ros2_driver__msg__ShipMotion__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xsens_mti_ros2_driver__msg__ShipMotion__Sequence__are_equal(const xsens_mti_ros2_driver__msg__ShipMotion__Sequence * lhs, const xsens_mti_ros2_driver__msg__ShipMotion__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xsens_mti_ros2_driver__msg__ShipMotion__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xsens_mti_ros2_driver__msg__ShipMotion__Sequence__copy(
  const xsens_mti_ros2_driver__msg__ShipMotion__Sequence * input,
  xsens_mti_ros2_driver__msg__ShipMotion__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xsens_mti_ros2_driver__msg__ShipMotion);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xsens_mti_ros2_driver__msg__ShipMotion * data =
      (xsens_mti_ros2_driver__msg__ShipMotion *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xsens_mti_ros2_driver__msg__ShipMotion__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xsens_mti_ros2_driver__msg__ShipMotion__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xsens_mti_ros2_driver__msg__ShipMotion__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
