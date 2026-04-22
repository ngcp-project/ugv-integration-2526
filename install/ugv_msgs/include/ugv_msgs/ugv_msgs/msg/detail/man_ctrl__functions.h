// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__MAN_CTRL__FUNCTIONS_H_
#define UGV_MSGS__MSG__DETAIL__MAN_CTRL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ugv_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ugv_msgs/msg/detail/man_ctrl__struct.h"

/// Initialize msg/ManCtrl message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ugv_msgs__msg__ManCtrl
 * )) before or use
 * ugv_msgs__msg__ManCtrl__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__ManCtrl__init(ugv_msgs__msg__ManCtrl * msg);

/// Finalize msg/ManCtrl message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__ManCtrl__fini(ugv_msgs__msg__ManCtrl * msg);

/// Create msg/ManCtrl message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ugv_msgs__msg__ManCtrl__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
ugv_msgs__msg__ManCtrl *
ugv_msgs__msg__ManCtrl__create();

/// Destroy msg/ManCtrl message.
/**
 * It calls
 * ugv_msgs__msg__ManCtrl__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__ManCtrl__destroy(ugv_msgs__msg__ManCtrl * msg);

/// Check for msg/ManCtrl message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__ManCtrl__are_equal(const ugv_msgs__msg__ManCtrl * lhs, const ugv_msgs__msg__ManCtrl * rhs);

/// Copy a msg/ManCtrl message.
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
ugv_msgs__msg__ManCtrl__copy(
  const ugv_msgs__msg__ManCtrl * input,
  ugv_msgs__msg__ManCtrl * output);

/// Initialize array of msg/ManCtrl messages.
/**
 * It allocates the memory for the number of elements and calls
 * ugv_msgs__msg__ManCtrl__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__ManCtrl__Sequence__init(ugv_msgs__msg__ManCtrl__Sequence * array, size_t size);

/// Finalize array of msg/ManCtrl messages.
/**
 * It calls
 * ugv_msgs__msg__ManCtrl__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__ManCtrl__Sequence__fini(ugv_msgs__msg__ManCtrl__Sequence * array);

/// Create array of msg/ManCtrl messages.
/**
 * It allocates the memory for the array and calls
 * ugv_msgs__msg__ManCtrl__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
ugv_msgs__msg__ManCtrl__Sequence *
ugv_msgs__msg__ManCtrl__Sequence__create(size_t size);

/// Destroy array of msg/ManCtrl messages.
/**
 * It calls
 * ugv_msgs__msg__ManCtrl__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
void
ugv_msgs__msg__ManCtrl__Sequence__destroy(ugv_msgs__msg__ManCtrl__Sequence * array);

/// Check for msg/ManCtrl message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ugv_msgs
bool
ugv_msgs__msg__ManCtrl__Sequence__are_equal(const ugv_msgs__msg__ManCtrl__Sequence * lhs, const ugv_msgs__msg__ManCtrl__Sequence * rhs);

/// Copy an array of msg/ManCtrl messages.
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
ugv_msgs__msg__ManCtrl__Sequence__copy(
  const ugv_msgs__msg__ManCtrl__Sequence * input,
  ugv_msgs__msg__ManCtrl__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UGV_MSGS__MSG__DETAIL__MAN_CTRL__FUNCTIONS_H_
