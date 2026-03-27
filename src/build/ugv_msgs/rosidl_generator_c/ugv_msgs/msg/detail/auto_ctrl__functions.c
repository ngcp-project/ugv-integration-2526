// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ugv_msgs:msg/AutoCtrl.idl
// generated code does not contain a copyright notice
#include "ugv_msgs/msg/detail/auto_ctrl__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ugv_msgs__msg__AutoCtrl__init(ugv_msgs__msg__AutoCtrl * msg)
{
  if (!msg) {
    return false;
  }
  // auto_en
  // heading_error
  return true;
}

void
ugv_msgs__msg__AutoCtrl__fini(ugv_msgs__msg__AutoCtrl * msg)
{
  if (!msg) {
    return;
  }
  // auto_en
  // heading_error
}

bool
ugv_msgs__msg__AutoCtrl__are_equal(const ugv_msgs__msg__AutoCtrl * lhs, const ugv_msgs__msg__AutoCtrl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // auto_en
  if (lhs->auto_en != rhs->auto_en) {
    return false;
  }
  // heading_error
  if (lhs->heading_error != rhs->heading_error) {
    return false;
  }
  return true;
}

bool
ugv_msgs__msg__AutoCtrl__copy(
  const ugv_msgs__msg__AutoCtrl * input,
  ugv_msgs__msg__AutoCtrl * output)
{
  if (!input || !output) {
    return false;
  }
  // auto_en
  output->auto_en = input->auto_en;
  // heading_error
  output->heading_error = input->heading_error;
  return true;
}

ugv_msgs__msg__AutoCtrl *
ugv_msgs__msg__AutoCtrl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__AutoCtrl * msg = (ugv_msgs__msg__AutoCtrl *)allocator.allocate(sizeof(ugv_msgs__msg__AutoCtrl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ugv_msgs__msg__AutoCtrl));
  bool success = ugv_msgs__msg__AutoCtrl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ugv_msgs__msg__AutoCtrl__destroy(ugv_msgs__msg__AutoCtrl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ugv_msgs__msg__AutoCtrl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ugv_msgs__msg__AutoCtrl__Sequence__init(ugv_msgs__msg__AutoCtrl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__AutoCtrl * data = NULL;

  if (size) {
    data = (ugv_msgs__msg__AutoCtrl *)allocator.zero_allocate(size, sizeof(ugv_msgs__msg__AutoCtrl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ugv_msgs__msg__AutoCtrl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ugv_msgs__msg__AutoCtrl__fini(&data[i - 1]);
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
ugv_msgs__msg__AutoCtrl__Sequence__fini(ugv_msgs__msg__AutoCtrl__Sequence * array)
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
      ugv_msgs__msg__AutoCtrl__fini(&array->data[i]);
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

ugv_msgs__msg__AutoCtrl__Sequence *
ugv_msgs__msg__AutoCtrl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ugv_msgs__msg__AutoCtrl__Sequence * array = (ugv_msgs__msg__AutoCtrl__Sequence *)allocator.allocate(sizeof(ugv_msgs__msg__AutoCtrl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ugv_msgs__msg__AutoCtrl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ugv_msgs__msg__AutoCtrl__Sequence__destroy(ugv_msgs__msg__AutoCtrl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ugv_msgs__msg__AutoCtrl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ugv_msgs__msg__AutoCtrl__Sequence__are_equal(const ugv_msgs__msg__AutoCtrl__Sequence * lhs, const ugv_msgs__msg__AutoCtrl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ugv_msgs__msg__AutoCtrl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ugv_msgs__msg__AutoCtrl__Sequence__copy(
  const ugv_msgs__msg__AutoCtrl__Sequence * input,
  ugv_msgs__msg__AutoCtrl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ugv_msgs__msg__AutoCtrl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ugv_msgs__msg__AutoCtrl * data =
      (ugv_msgs__msg__AutoCtrl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ugv_msgs__msg__AutoCtrl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ugv_msgs__msg__AutoCtrl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ugv_msgs__msg__AutoCtrl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
