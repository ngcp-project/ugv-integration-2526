// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ugv_msgs/msg/detail/man_ctrl__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ugv_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ManCtrl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ugv_msgs::msg::ManCtrl(_init);
}

void ManCtrl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ugv_msgs::msg::ManCtrl *>(message_memory);
  typed_message->~ManCtrl();
}

size_t size_function__ManCtrl__arm_cmd(const void * untyped_member)
{
  (void)untyped_member;
  return 5;
}

const void * get_const_function__ManCtrl__arm_cmd(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 5> *>(untyped_member);
  return &member[index];
}

void * get_function__ManCtrl__arm_cmd(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 5> *>(untyped_member);
  return &member[index];
}

void fetch_function__ManCtrl__arm_cmd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ManCtrl__arm_cmd(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ManCtrl__arm_cmd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ManCtrl__arm_cmd(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ManCtrl_message_member_array[4] = {
  {
    "auto_en",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs::msg::ManCtrl, auto_en),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "linear_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs::msg::ManCtrl, linear_vel),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "steer_cmd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs::msg::ManCtrl, steer_cmd),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "arm_cmd",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    5,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs::msg::ManCtrl, arm_cmd),  // bytes offset in struct
    nullptr,  // default value
    size_function__ManCtrl__arm_cmd,  // size() function pointer
    get_const_function__ManCtrl__arm_cmd,  // get_const(index) function pointer
    get_function__ManCtrl__arm_cmd,  // get(index) function pointer
    fetch_function__ManCtrl__arm_cmd,  // fetch(index, &value) function pointer
    assign_function__ManCtrl__arm_cmd,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ManCtrl_message_members = {
  "ugv_msgs::msg",  // message namespace
  "ManCtrl",  // message name
  4,  // number of fields
  sizeof(ugv_msgs::msg::ManCtrl),
  ManCtrl_message_member_array,  // message members
  ManCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  ManCtrl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ManCtrl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ManCtrl_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ugv_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ugv_msgs::msg::ManCtrl>()
{
  return &::ugv_msgs::msg::rosidl_typesupport_introspection_cpp::ManCtrl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ugv_msgs, msg, ManCtrl)() {
  return &::ugv_msgs::msg::rosidl_typesupport_introspection_cpp::ManCtrl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
