// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ugv_msgs:msg/AutoCtrl.idl
// generated code does not contain a copyright notice
#include "ugv_msgs/msg/detail/auto_ctrl__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ugv_msgs/msg/detail/auto_ctrl__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ugv_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ugv_msgs
cdr_serialize(
  const ugv_msgs::msg::AutoCtrl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: auto_en
  cdr << (ros_message.auto_en ? true : false);
  // Member: heading_error
  cdr << ros_message.heading_error;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ugv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ugv_msgs::msg::AutoCtrl & ros_message)
{
  // Member: auto_en
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.auto_en = tmp ? true : false;
  }

  // Member: heading_error
  cdr >> ros_message.heading_error;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ugv_msgs
get_serialized_size(
  const ugv_msgs::msg::AutoCtrl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: auto_en
  {
    size_t item_size = sizeof(ros_message.auto_en);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: heading_error
  {
    size_t item_size = sizeof(ros_message.heading_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ugv_msgs
max_serialized_size_AutoCtrl(
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


  // Member: auto_en
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: heading_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ugv_msgs::msg::AutoCtrl;
    is_plain =
      (
      offsetof(DataType, heading_error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _AutoCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ugv_msgs::msg::AutoCtrl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _AutoCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ugv_msgs::msg::AutoCtrl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _AutoCtrl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ugv_msgs::msg::AutoCtrl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _AutoCtrl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_AutoCtrl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _AutoCtrl__callbacks = {
  "ugv_msgs::msg",
  "AutoCtrl",
  _AutoCtrl__cdr_serialize,
  _AutoCtrl__cdr_deserialize,
  _AutoCtrl__get_serialized_size,
  _AutoCtrl__max_serialized_size
};

static rosidl_message_type_support_t _AutoCtrl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_AutoCtrl__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ugv_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ugv_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<ugv_msgs::msg::AutoCtrl>()
{
  return &ugv_msgs::msg::typesupport_fastrtps_cpp::_AutoCtrl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ugv_msgs, msg, AutoCtrl)() {
  return &ugv_msgs::msg::typesupport_fastrtps_cpp::_AutoCtrl__handle;
}

#ifdef __cplusplus
}
#endif
