// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
xsens_mti_ros2_driver__msg__XsStatusWord__init(xsens_mti_ros2_driver__msg__XsStatusWord * msg)
{
  if (!msg) {
    return false;
  }
  // selftest
  // filter_valid
  // gnss_fix
  // no_rotation_update_status
  // representative_motion
  // clock_bias_estimation
  // clipflag_acc_x
  // clipflag_acc_y
  // clipflag_acc_z
  // clipflag_gyr_x
  // clipflag_gyr_y
  // clipflag_gyr_z
  // clipflag_mag_x
  // clipflag_mag_y
  // clipflag_mag_z
  // clipping_indication
  // syncin_marker
  // syncout_marker
  // filter_mode
  // have_gnss_time_pulse
  // rtk_status
  return true;
}

void
xsens_mti_ros2_driver__msg__XsStatusWord__fini(xsens_mti_ros2_driver__msg__XsStatusWord * msg)
{
  if (!msg) {
    return;
  }
  // selftest
  // filter_valid
  // gnss_fix
  // no_rotation_update_status
  // representative_motion
  // clock_bias_estimation
  // clipflag_acc_x
  // clipflag_acc_y
  // clipflag_acc_z
  // clipflag_gyr_x
  // clipflag_gyr_y
  // clipflag_gyr_z
  // clipflag_mag_x
  // clipflag_mag_y
  // clipflag_mag_z
  // clipping_indication
  // syncin_marker
  // syncout_marker
  // filter_mode
  // have_gnss_time_pulse
  // rtk_status
}

bool
xsens_mti_ros2_driver__msg__XsStatusWord__are_equal(const xsens_mti_ros2_driver__msg__XsStatusWord * lhs, const xsens_mti_ros2_driver__msg__XsStatusWord * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // selftest
  if (lhs->selftest != rhs->selftest) {
    return false;
  }
  // filter_valid
  if (lhs->filter_valid != rhs->filter_valid) {
    return false;
  }
  // gnss_fix
  if (lhs->gnss_fix != rhs->gnss_fix) {
    return false;
  }
  // no_rotation_update_status
  if (lhs->no_rotation_update_status != rhs->no_rotation_update_status) {
    return false;
  }
  // representative_motion
  if (lhs->representative_motion != rhs->representative_motion) {
    return false;
  }
  // clock_bias_estimation
  if (lhs->clock_bias_estimation != rhs->clock_bias_estimation) {
    return false;
  }
  // clipflag_acc_x
  if (lhs->clipflag_acc_x != rhs->clipflag_acc_x) {
    return false;
  }
  // clipflag_acc_y
  if (lhs->clipflag_acc_y != rhs->clipflag_acc_y) {
    return false;
  }
  // clipflag_acc_z
  if (lhs->clipflag_acc_z != rhs->clipflag_acc_z) {
    return false;
  }
  // clipflag_gyr_x
  if (lhs->clipflag_gyr_x != rhs->clipflag_gyr_x) {
    return false;
  }
  // clipflag_gyr_y
  if (lhs->clipflag_gyr_y != rhs->clipflag_gyr_y) {
    return false;
  }
  // clipflag_gyr_z
  if (lhs->clipflag_gyr_z != rhs->clipflag_gyr_z) {
    return false;
  }
  // clipflag_mag_x
  if (lhs->clipflag_mag_x != rhs->clipflag_mag_x) {
    return false;
  }
  // clipflag_mag_y
  if (lhs->clipflag_mag_y != rhs->clipflag_mag_y) {
    return false;
  }
  // clipflag_mag_z
  if (lhs->clipflag_mag_z != rhs->clipflag_mag_z) {
    return false;
  }
  // clipping_indication
  if (lhs->clipping_indication != rhs->clipping_indication) {
    return false;
  }
  // syncin_marker
  if (lhs->syncin_marker != rhs->syncin_marker) {
    return false;
  }
  // syncout_marker
  if (lhs->syncout_marker != rhs->syncout_marker) {
    return false;
  }
  // filter_mode
  if (lhs->filter_mode != rhs->filter_mode) {
    return false;
  }
  // have_gnss_time_pulse
  if (lhs->have_gnss_time_pulse != rhs->have_gnss_time_pulse) {
    return false;
  }
  // rtk_status
  if (lhs->rtk_status != rhs->rtk_status) {
    return false;
  }
  return true;
}

bool
xsens_mti_ros2_driver__msg__XsStatusWord__copy(
  const xsens_mti_ros2_driver__msg__XsStatusWord * input,
  xsens_mti_ros2_driver__msg__XsStatusWord * output)
{
  if (!input || !output) {
    return false;
  }
  // selftest
  output->selftest = input->selftest;
  // filter_valid
  output->filter_valid = input->filter_valid;
  // gnss_fix
  output->gnss_fix = input->gnss_fix;
  // no_rotation_update_status
  output->no_rotation_update_status = input->no_rotation_update_status;
  // representative_motion
  output->representative_motion = input->representative_motion;
  // clock_bias_estimation
  output->clock_bias_estimation = input->clock_bias_estimation;
  // clipflag_acc_x
  output->clipflag_acc_x = input->clipflag_acc_x;
  // clipflag_acc_y
  output->clipflag_acc_y = input->clipflag_acc_y;
  // clipflag_acc_z
  output->clipflag_acc_z = input->clipflag_acc_z;
  // clipflag_gyr_x
  output->clipflag_gyr_x = input->clipflag_gyr_x;
  // clipflag_gyr_y
  output->clipflag_gyr_y = input->clipflag_gyr_y;
  // clipflag_gyr_z
  output->clipflag_gyr_z = input->clipflag_gyr_z;
  // clipflag_mag_x
  output->clipflag_mag_x = input->clipflag_mag_x;
  // clipflag_mag_y
  output->clipflag_mag_y = input->clipflag_mag_y;
  // clipflag_mag_z
  output->clipflag_mag_z = input->clipflag_mag_z;
  // clipping_indication
  output->clipping_indication = input->clipping_indication;
  // syncin_marker
  output->syncin_marker = input->syncin_marker;
  // syncout_marker
  output->syncout_marker = input->syncout_marker;
  // filter_mode
  output->filter_mode = input->filter_mode;
  // have_gnss_time_pulse
  output->have_gnss_time_pulse = input->have_gnss_time_pulse;
  // rtk_status
  output->rtk_status = input->rtk_status;
  return true;
}

xsens_mti_ros2_driver__msg__XsStatusWord *
xsens_mti_ros2_driver__msg__XsStatusWord__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsens_mti_ros2_driver__msg__XsStatusWord * msg = (xsens_mti_ros2_driver__msg__XsStatusWord *)allocator.allocate(sizeof(xsens_mti_ros2_driver__msg__XsStatusWord), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(xsens_mti_ros2_driver__msg__XsStatusWord));
  bool success = xsens_mti_ros2_driver__msg__XsStatusWord__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
xsens_mti_ros2_driver__msg__XsStatusWord__destroy(xsens_mti_ros2_driver__msg__XsStatusWord * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    xsens_mti_ros2_driver__msg__XsStatusWord__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__init(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsens_mti_ros2_driver__msg__XsStatusWord * data = NULL;

  if (size) {
    data = (xsens_mti_ros2_driver__msg__XsStatusWord *)allocator.zero_allocate(size, sizeof(xsens_mti_ros2_driver__msg__XsStatusWord), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = xsens_mti_ros2_driver__msg__XsStatusWord__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        xsens_mti_ros2_driver__msg__XsStatusWord__fini(&data[i - 1]);
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
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__fini(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array)
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
      xsens_mti_ros2_driver__msg__XsStatusWord__fini(&array->data[i]);
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

xsens_mti_ros2_driver__msg__XsStatusWord__Sequence *
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array = (xsens_mti_ros2_driver__msg__XsStatusWord__Sequence *)allocator.allocate(sizeof(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__destroy(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__are_equal(const xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * lhs, const xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!xsens_mti_ros2_driver__msg__XsStatusWord__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__copy(
  const xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * input,
  xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(xsens_mti_ros2_driver__msg__XsStatusWord);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    xsens_mti_ros2_driver__msg__XsStatusWord * data =
      (xsens_mti_ros2_driver__msg__XsStatusWord *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!xsens_mti_ros2_driver__msg__XsStatusWord__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          xsens_mti_ros2_driver__msg__XsStatusWord__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!xsens_mti_ros2_driver__msg__XsStatusWord__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
