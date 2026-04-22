// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ugv_msgs/msg/detail/man_ctrl__rosidl_typesupport_introspection_c.h"
#include "ugv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ugv_msgs/msg/detail/man_ctrl__functions.h"
#include "ugv_msgs/msg/detail/man_ctrl__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ugv_msgs__msg__ManCtrl__init(message_memory);
}

void ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_fini_function(void * message_memory)
{
  ugv_msgs__msg__ManCtrl__fini(message_memory);
}

size_t ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__size_function__ManCtrl__arm_cmd(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__get_const_function__ManCtrl__arm_cmd(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__get_function__ManCtrl__arm_cmd(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__fetch_function__ManCtrl__arm_cmd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__get_const_function__ManCtrl__arm_cmd(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__assign_function__ManCtrl__arm_cmd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__get_function__ManCtrl__arm_cmd(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_member_array[4] = {
  {
    "auto_en",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs__msg__ManCtrl, auto_en),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs__msg__ManCtrl, linear_vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steer_cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs__msg__ManCtrl, steer_cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arm_cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(ugv_msgs__msg__ManCtrl, arm_cmd),  // bytes offset in struct
    NULL,  // default value
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__size_function__ManCtrl__arm_cmd,  // size() function pointer
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__get_const_function__ManCtrl__arm_cmd,  // get_const(index) function pointer
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__get_function__ManCtrl__arm_cmd,  // get(index) function pointer
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__fetch_function__ManCtrl__arm_cmd,  // fetch(index, &value) function pointer
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__assign_function__ManCtrl__arm_cmd,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_members = {
  "ugv_msgs__msg",  // message namespace
  "ManCtrl",  // message name
  4,  // number of fields
  sizeof(ugv_msgs__msg__ManCtrl),
  ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_member_array,  // message members
  ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_type_support_handle = {
  0,
  &ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ugv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ugv_msgs, msg, ManCtrl)() {
  if (!ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_type_support_handle.typesupport_identifier) {
    ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ugv_msgs__msg__ManCtrl__rosidl_typesupport_introspection_c__ManCtrl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
