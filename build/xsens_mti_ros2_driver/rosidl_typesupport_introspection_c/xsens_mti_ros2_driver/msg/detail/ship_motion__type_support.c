// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "xsens_mti_ros2_driver/msg/detail/ship_motion__rosidl_typesupport_introspection_c.h"
#include "xsens_mti_ros2_driver/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "xsens_mti_ros2_driver/msg/detail/ship_motion__functions.h"
#include "xsens_mti_ros2_driver/msg/detail/ship_motion__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  xsens_mti_ros2_driver__msg__ShipMotion__init(message_memory);
}

void xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_fini_function(void * message_memory)
{
  xsens_mti_ros2_driver__msg__ShipMotion__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_mti_ros2_driver__msg__ShipMotion, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heave_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_mti_ros2_driver__msg__ShipMotion, heave_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "heave_period",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(xsens_mti_ros2_driver__msg__ShipMotion, heave_period),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_members = {
  "xsens_mti_ros2_driver__msg",  // message namespace
  "ShipMotion",  // message name
  3,  // number of fields
  sizeof(xsens_mti_ros2_driver__msg__ShipMotion),
  xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_member_array,  // message members
  xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_init_function,  // function to initialize message memory (memory has to be allocated)
  xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_type_support_handle = {
  0,
  &xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_xsens_mti_ros2_driver
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, xsens_mti_ros2_driver, msg, ShipMotion)() {
  xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_type_support_handle.typesupport_identifier) {
    xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &xsens_mti_ros2_driver__msg__ShipMotion__rosidl_typesupport_introspection_c__ShipMotion_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
