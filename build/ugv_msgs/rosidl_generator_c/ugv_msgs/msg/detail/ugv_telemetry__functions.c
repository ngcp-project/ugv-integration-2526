// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ugv_msgs:msg/UGVTelemetry.idl
// generated code does not contain a copyright notice
#include "ugv_msgs/msg/detail/ugv_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ugv_msgs__msg__UGVTelemetry__init(ugv_msgs__msg__UGVTelemetry * msg)
{
  if (!msg) {
    return false;
  }
  // speed_fps
  // pitch_deg
  // yaw_deg
  // roll_deg
  // altitude_ft
  // latitude
  // longitude
  return true;
}

void
ugv_msgs__msg__UGVTelemetry__fini(ugv_msgs__msg__UGVTelemetry * msg)
{
  if (!msg) {
    return;
  }
  // speed_fps
  // pitch_deg
  // yaw_deg
  // roll_deg
  // altitude_ft
  // latitude
  // longitude
}

bool
ugv_msgs__msg__UGVTelemetry__are_equal(const ugv_msgs__msg__UGVTelemetry * lhs, const ugv_msgs__msg__UGVTelemetry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // speed_fps
  if (lhs->speed_fps != rhs->speed_fps) {
    return false;
  }
  // pitch_deg
  if (lhs->pitch_deg != rhs->pitch_deg) {
    return false;
  }
  // yaw_deg
  if (lhs->yaw_deg != rhs->yaw_deg) {
    return false;
  }
  // roll_deg
  if (lhs->roll_deg != rhs->roll_deg) {
    return false;
  }
  // altitude_ft
  if (lhs->altitude_ft != rhs->altitude_ft) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  return true;
}

bool
ugv_msgs__msg__UGVTelemetry__copy(
  const ugv_msgs__msg__UGVTelemetry * input,
  ugv_msgs__msg__UGVTelemetry * output)
{
  if (!input || !output) {
    return false;
  }
  // speed_fps
  output->speed_fps = input->speed_fps;
  // pitch_deg
  output->pitch_deg = input->pitch_deg;
  // yaw_deg
  output->yaw_deg = input->yaw_deg;
  // roll_deg
  output->roll_deg = input->roll_deg;
  // altitude_ft
  output->altitude_ft = input->altitude_ft;
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  return true;
}

ugv_msgs__msg__UGVTelemetry *
ugv_msgs__msg__UGVTelemetry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__UGVTelemetry * msg = (ugv_msgs__msg__UGVTelemetry *)allocator.allocate(sizeof(ugv_msgs__msg__UGVTelemetry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ugv_msgs__msg__UGVTelemetry));
  bool success = ugv_msgs__msg__UGVTelemetry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ugv_msgs__msg__UGVTelemetry__destroy(ugv_msgs__msg__UGVTelemetry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ugv_msgs__msg__UGVTelemetry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ugv_msgs__msg__UGVTelemetry__Sequence__init(ugv_msgs__msg__UGVTelemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__UGVTelemetry * data = NULL;

  if (size) {
    data = (ugv_msgs__msg__UGVTelemetry *)allocator.zero_allocate(size, sizeof(ugv_msgs__msg__UGVTelemetry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ugv_msgs__msg__UGVTelemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ugv_msgs__msg__UGVTelemetry__fini(&data[i - 1]);
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
ugv_msgs__msg__UGVTelemetry__Sequence__fini(ugv_msgs__msg__UGVTelemetry__Sequence * array)
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
      ugv_msgs__msg__UGVTelemetry__fini(&array->data[i]);
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

ugv_msgs__msg__UGVTelemetry__Sequence *
ugv_msgs__msg__UGVTelemetry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__UGVTelemetry__Sequence * array = (ugv_msgs__msg__UGVTelemetry__Sequence *)allocator.allocate(sizeof(ugv_msgs__msg__UGVTelemetry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ugv_msgs__msg__UGVTelemetry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ugv_msgs__msg__UGVTelemetry__Sequence__destroy(ugv_msgs__msg__UGVTelemetry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ugv_msgs__msg__UGVTelemetry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ugv_msgs__msg__UGVTelemetry__Sequence__are_equal(const ugv_msgs__msg__UGVTelemetry__Sequence * lhs, const ugv_msgs__msg__UGVTelemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ugv_msgs__msg__UGVTelemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ugv_msgs__msg__UGVTelemetry__Sequence__copy(
  const ugv_msgs__msg__UGVTelemetry__Sequence * input,
  ugv_msgs__msg__UGVTelemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ugv_msgs__msg__UGVTelemetry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ugv_msgs__msg__UGVTelemetry * data =
      (ugv_msgs__msg__UGVTelemetry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ugv_msgs__msg__UGVTelemetry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ugv_msgs__msg__UGVTelemetry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ugv_msgs__msg__UGVTelemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
