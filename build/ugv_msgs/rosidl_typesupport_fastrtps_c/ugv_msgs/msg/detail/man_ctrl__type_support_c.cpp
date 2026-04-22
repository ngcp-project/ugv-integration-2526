// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice
#include "ugv_msgs/msg/detail/man_ctrl__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ugv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ugv_msgs/msg/detail/man_ctrl__struct.h"
#include "ugv_msgs/msg/detail/man_ctrl__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ManCtrl__ros_msg_type = ugv_msgs__msg__ManCtrl;

static bool _ManCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ManCtrl__ros_msg_type * ros_message = static_cast<const _ManCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: auto_en
  {
    cdr << (ros_message->auto_en ? true : false);
  }

  // Field name: linear_vel
  {
    cdr << ros_message->linear_vel;
  }

  // Field name: steer_cmd
  {
    cdr << ros_message->steer_cmd;
  }

  // Field name: arm_cmd
  {
    size_t size = 2;
    auto array_ptr = ros_message->arm_cmd;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _ManCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ManCtrl__ros_msg_type * ros_message = static_cast<_ManCtrl__ros_msg_type *>(untyped_ros_message);
  // Field name: auto_en
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->auto_en = tmp ? true : false;
  }

  // Field name: linear_vel
  {
    cdr >> ros_message->linear_vel;
  }

  // Field name: steer_cmd
  {
    cdr >> ros_message->steer_cmd;
  }

  // Field name: arm_cmd
  {
    size_t size = 2;
    auto array_ptr = ros_message->arm_cmd;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ugv_msgs
size_t get_serialized_size_ugv_msgs__msg__ManCtrl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ManCtrl__ros_msg_type * ros_message = static_cast<const _ManCtrl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name auto_en
  {
    size_t item_size = sizeof(ros_message->auto_en);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name linear_vel
  {
    size_t item_size = sizeof(ros_message->linear_vel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name steer_cmd
  {
    size_t item_size = sizeof(ros_message->steer_cmd);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name arm_cmd
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->arm_cmd;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ManCtrl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ugv_msgs__msg__ManCtrl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ugv_msgs
size_t max_serialized_size_ugv_msgs__msg__ManCtrl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: auto_en
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: linear_vel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: steer_cmd
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: arm_cmd
  {
    size_t array_size = 2;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ugv_msgs__msg__ManCtrl;
    is_plain =
      (
      offsetof(DataType, arm_cmd) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ManCtrl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ugv_msgs__msg__ManCtrl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ManCtrl = {
  "ugv_msgs::msg",
  "ManCtrl",
  _ManCtrl__cdr_serialize,
  _ManCtrl__cdr_deserialize,
  _ManCtrl__get_serialized_size,
  _ManCtrl__max_serialized_size
};

static rosidl_message_type_support_t _ManCtrl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ManCtrl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ugv_msgs, msg, ManCtrl)() {
  return &_ManCtrl__type_support;
}

#if defined(__cplusplus)
}
#endif
