// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__FUNCTIONS_H_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "xsens_mti_ros2_driver/msg/rosidl_generator_c__visibility_control.h"

#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.h"

/// Initialize msg/XsStatusWord message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * xsens_mti_ros2_driver__msg__XsStatusWord
 * )) before or use
 * xsens_mti_ros2_driver__msg__XsStatusWord__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
bool
xsens_mti_ros2_driver__msg__XsStatusWord__init(xsens_mti_ros2_driver__msg__XsStatusWord * msg);

/// Finalize msg/XsStatusWord message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
void
xsens_mti_ros2_driver__msg__XsStatusWord__fini(xsens_mti_ros2_driver__msg__XsStatusWord * msg);

/// Create msg/XsStatusWord message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * xsens_mti_ros2_driver__msg__XsStatusWord__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
xsens_mti_ros2_driver__msg__XsStatusWord *
xsens_mti_ros2_driver__msg__XsStatusWord__create();

/// Destroy msg/XsStatusWord message.
/**
 * It calls
 * xsens_mti_ros2_driver__msg__XsStatusWord__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
void
xsens_mti_ros2_driver__msg__XsStatusWord__destroy(xsens_mti_ros2_driver__msg__XsStatusWord * msg);

/// Check for msg/XsStatusWord message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
bool
xsens_mti_ros2_driver__msg__XsStatusWord__are_equal(const xsens_mti_ros2_driver__msg__XsStatusWord * lhs, const xsens_mti_ros2_driver__msg__XsStatusWord * rhs);

/// Copy a msg/XsStatusWord message.
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
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
bool
xsens_mti_ros2_driver__msg__XsStatusWord__copy(
  const xsens_mti_ros2_driver__msg__XsStatusWord * input,
  xsens_mti_ros2_driver__msg__XsStatusWord * output);

/// Initialize array of msg/XsStatusWord messages.
/**
 * It allocates the memory for the number of elements and calls
 * xsens_mti_ros2_driver__msg__XsStatusWord__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
bool
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__init(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array, size_t size);

/// Finalize array of msg/XsStatusWord messages.
/**
 * It calls
 * xsens_mti_ros2_driver__msg__XsStatusWord__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
void
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__fini(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array);

/// Create array of msg/XsStatusWord messages.
/**
 * It allocates the memory for the array and calls
 * xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence *
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__create(size_t size);

/// Destroy array of msg/XsStatusWord messages.
/**
 * It calls
 * xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
void
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__destroy(xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * array);

/// Check for msg/XsStatusWord message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
bool
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__are_equal(const xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * lhs, const xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * rhs);

/// Copy an array of msg/XsStatusWord messages.
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
ROSIDL_GENERATOR_C_PUBLIC_xsens_mti_ros2_driver
bool
xsens_mti_ros2_driver__msg__XsStatusWord__Sequence__copy(
  const xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * input,
  xsens_mti_ros2_driver__msg__XsStatusWord__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__XS_STATUS_WORD__FUNCTIONS_H_
