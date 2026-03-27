// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ugv_msgs:msg/UGVTelemetry.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__FUNCTIONS_H_
#define UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ugv_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ugv_msgs/msg/detail/ugv_telemetry__struct.h"

/// Initialize msg/UGVTelemetry message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ugv_msgs__msg__UGVTelemetry
 * )) before or use
 * ugv_msgs__msg__UGVTelemetry__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__UGVTelemetry__init(ugv_msgs__msg__UGVTelemetry * msg);

/// Finalize msg/UGVTelemetry message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__UGVTelemetry__fini(ugv_msgs__msg__UGVTelemetry * msg);

/// Create msg/UGVTelemetry message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ugv_msgs__msg__UGVTelemetry__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
ugv_msgs__msg__UGVTelemetry *
ugv_msgs__msg__UGVTelemetry__create();

/// Destroy msg/UGVTelemetry message.
/**
 * It calls
 * ugv_msgs__msg__UGVTelemetry__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__UGVTelemetry__destroy(ugv_msgs__msg__UGVTelemetry * msg);

/// Check for msg/UGVTelemetry message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__UGVTelemetry__are_equal(const ugv_msgs__msg__UGVTelemetry * lhs, const ugv_msgs__msg__UGVTelemetry * rhs);

/// Copy a msg/UGVTelemetry message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__UGVTelemetry__copy(
  const ugv_msgs__msg__UGVTelemetry * input,
  ugv_msgs__msg__UGVTelemetry * output);

/// Initialize array of msg/UGVTelemetry messages.
/**
 * It allocates the memory for the number of elements and calls
 * ugv_msgs__msg__UGVTelemetry__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__UGVTelemetry__Sequence__init(ugv_msgs__msg__UGVTelemetry__Sequence * array, size_t size);

/// Finalize array of msg/UGVTelemetry messages.
/**
 * It calls
 * ugv_msgs__msg__UGVTelemetry__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__UGVTelemetry__Sequence__fini(ugv_msgs__msg__UGVTelemetry__Sequence * array);

/// Create array of msg/UGVTelemetry messages.
/**
 * It allocates the memory for the array and calls
 * ugv_msgs__msg__UGVTelemetry__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
ugv_msgs__msg__UGVTelemetry__Sequence *
ugv_msgs__msg__UGVTelemetry__Sequence__create(size_t size);

/// Destroy array of msg/UGVTelemetry messages.
/**
 * It calls
 * ugv_msgs__msg__UGVTelemetry__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__UGVTelemetry__Sequence__destroy(ugv_msgs__msg__UGVTelemetry__Sequence * array);

/// Check for msg/UGVTelemetry message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__UGVTelemetry__Sequence__are_equal(const ugv_msgs__msg__UGVTelemetry__Sequence * lhs, const ugv_msgs__msg__UGVTelemetry__Sequence * rhs);

/// Copy an array of msg/UGVTelemetry messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__UGVTelemetry__Sequence__copy(
  const ugv_msgs__msg__UGVTelemetry__Sequence * input,
  ugv_msgs__msg__UGVTelemetry__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UGV_MSGS__MSG__DETAIL__UGV_TELEMETRY__FUNCTIONS_H_
