// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice
#include "ugv_msgs/msg/detail/man_ctrl__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ugv_msgs__msg__ManCtrl__init(ugv_msgs__msg__ManCtrl * msg)
{
  if (!msg) {
    return false;
  }
  // auto_en
  // linear_vel
  // steer_cmd
  // arm_cmd
  return true;
}

void
ugv_msgs__msg__ManCtrl__fini(ugv_msgs__msg__ManCtrl * msg)
{
  if (!msg) {
    return;
  }
  // auto_en
  // linear_vel
  // steer_cmd
  // arm_cmd
}

bool
ugv_msgs__msg__ManCtrl__are_equal(const ugv_msgs__msg__ManCtrl * lhs, const ugv_msgs__msg__ManCtrl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // auto_en
  if (lhs->auto_en != rhs->auto_en) {
    return false;
  }
  // linear_vel
  if (lhs->linear_vel != rhs->linear_vel) {
    return false;
  }
  // steer_cmd
  if (lhs->steer_cmd != rhs->steer_cmd) {
    return false;
  }
  // arm_cmd
  for (size_t i = 0; i < 5; ++i) {
    if (lhs->arm_cmd[i] != rhs->arm_cmd[i]) {
      return false;
    }
  }
  return true;
}

bool
ugv_msgs__msg__ManCtrl__copy(
  const ugv_msgs__msg__ManCtrl * input,
  ugv_msgs__msg__ManCtrl * output)
{
  if (!input || !output) {
    return false;
  }
  // auto_en
  output->auto_en = input->auto_en;
  // linear_vel
  output->linear_vel = input->linear_vel;
  // steer_cmd
  output->steer_cmd = input->steer_cmd;
  // arm_cmd
  for (size_t i = 0; i < 5; ++i) {
    output->arm_cmd[i] = input->arm_cmd[i];
  }
  return true;
}

ugv_msgs__msg__ManCtrl *
ugv_msgs__msg__ManCtrl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__ManCtrl * msg = (ugv_msgs__msg__ManCtrl *)allocator.allocate(sizeof(ugv_msgs__msg__ManCtrl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ugv_msgs__msg__ManCtrl));
  bool success = ugv_msgs__msg__ManCtrl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ugv_msgs__msg__ManCtrl__destroy(ugv_msgs__msg__ManCtrl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ugv_msgs__msg__ManCtrl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ugv_msgs__msg__ManCtrl__Sequence__init(ugv_msgs__msg__ManCtrl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__ManCtrl * data = NULL;

  if (size) {
    data = (ugv_msgs__msg__ManCtrl *)allocator.zero_allocate(size, sizeof(ugv_msgs__msg__ManCtrl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ugv_msgs__msg__ManCtrl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ugv_msgs__msg__ManCtrl__fini(&data[i - 1]);
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
ugv_msgs__msg__ManCtrl__Sequence__fini(ugv_msgs__msg__ManCtrl__Sequence * array)
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
      ugv_msgs__msg__ManCtrl__fini(&array->data[i]);
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

ugv_msgs__msg__ManCtrl__Sequence *
ugv_msgs__msg__ManCtrl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__ManCtrl__Sequence * array = (ugv_msgs__msg__ManCtrl__Sequence *)allocator.allocate(sizeof(ugv_msgs__msg__ManCtrl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ugv_msgs__msg__ManCtrl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ugv_msgs__msg__ManCtrl__Sequence__destroy(ugv_msgs__msg__ManCtrl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ugv_msgs__msg__ManCtrl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ugv_msgs__msg__ManCtrl__Sequence__are_equal(const ugv_msgs__msg__ManCtrl__Sequence * lhs, const ugv_msgs__msg__ManCtrl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ugv_msgs__msg__ManCtrl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ugv_msgs__msg__ManCtrl__Sequence__copy(
  const ugv_msgs__msg__ManCtrl__Sequence * input,
  ugv_msgs__msg__ManCtrl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ugv_msgs__msg__ManCtrl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ugv_msgs__msg__ManCtrl * data =
      (ugv_msgs__msg__ManCtrl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ugv_msgs__msg__ManCtrl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ugv_msgs__msg__ManCtrl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ugv_msgs__msg__ManCtrl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
