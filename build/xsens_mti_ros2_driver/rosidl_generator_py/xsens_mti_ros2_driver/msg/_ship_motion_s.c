// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "xsens_mti_ros2_driver/msg/detail/ship_motion__struct.h"
#include "xsens_mti_ros2_driver/msg/detail/ship_motion__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool xsens_mti_ros2_driver__msg__ship_motion__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("xsens_mti_ros2_driver.msg._ship_motion.ShipMotion", full_classname_dest, 49) == 0);
  }
  xsens_mti_ros2_driver__msg__ShipMotion * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // heave_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "heave_position");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heave_position = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heave_period
    PyObject * field = PyObject_GetAttrString(_pymsg, "heave_period");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heave_period = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xsens_mti_ros2_driver__msg__ship_motion__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ShipMotion */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xsens_mti_ros2_driver.msg._ship_motion");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ShipMotion");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xsens_mti_ros2_driver__msg__ShipMotion * ros_message = (xsens_mti_ros2_driver__msg__ShipMotion *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heave_position
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heave_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heave_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heave_period
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heave_period);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heave_period", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
