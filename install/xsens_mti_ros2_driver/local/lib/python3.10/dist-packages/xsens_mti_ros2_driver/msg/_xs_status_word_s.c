// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
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
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.h"
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool xsens_mti_ros2_driver__msg__xs_status_word__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[55];
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
    assert(strncmp("xsens_mti_ros2_driver.msg._xs_status_word.XsStatusWord", full_classname_dest, 54) == 0);
  }
  xsens_mti_ros2_driver__msg__XsStatusWord * ros_message = _ros_message;
  {  // selftest
    PyObject * field = PyObject_GetAttrString(_pymsg, "selftest");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->selftest = (Py_True == field);
    Py_DECREF(field);
  }
  {  // filter_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "filter_valid");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->filter_valid = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gnss_fix
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_fix");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->gnss_fix = (Py_True == field);
    Py_DECREF(field);
  }
  {  // no_rotation_update_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "no_rotation_update_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->no_rotation_update_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // representative_motion
    PyObject * field = PyObject_GetAttrString(_pymsg, "representative_motion");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->representative_motion = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clock_bias_estimation
    PyObject * field = PyObject_GetAttrString(_pymsg, "clock_bias_estimation");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clock_bias_estimation = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_acc_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_acc_x");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_acc_x = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_acc_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_acc_y");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_acc_y = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_acc_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_acc_z");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_acc_z = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_gyr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_gyr_x");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_gyr_x = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_gyr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_gyr_y");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_gyr_y = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_gyr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_gyr_z");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_gyr_z = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_mag_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_mag_x");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_mag_x = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_mag_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_mag_y");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_mag_y = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipflag_mag_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipflag_mag_z");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipflag_mag_z = (Py_True == field);
    Py_DECREF(field);
  }
  {  // clipping_indication
    PyObject * field = PyObject_GetAttrString(_pymsg, "clipping_indication");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->clipping_indication = (Py_True == field);
    Py_DECREF(field);
  }
  {  // syncin_marker
    PyObject * field = PyObject_GetAttrString(_pymsg, "syncin_marker");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->syncin_marker = (Py_True == field);
    Py_DECREF(field);
  }
  {  // syncout_marker
    PyObject * field = PyObject_GetAttrString(_pymsg, "syncout_marker");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->syncout_marker = (Py_True == field);
    Py_DECREF(field);
  }
  {  // filter_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "filter_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->filter_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // have_gnss_time_pulse
    PyObject * field = PyObject_GetAttrString(_pymsg, "have_gnss_time_pulse");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->have_gnss_time_pulse = (Py_True == field);
    Py_DECREF(field);
  }
  {  // rtk_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtk_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rtk_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * xsens_mti_ros2_driver__msg__xs_status_word__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of XsStatusWord */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("xsens_mti_ros2_driver.msg._xs_status_word");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "XsStatusWord");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  xsens_mti_ros2_driver__msg__XsStatusWord * ros_message = (xsens_mti_ros2_driver__msg__XsStatusWord *)raw_ros_message;
  {  // selftest
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->selftest ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "selftest", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // filter_valid
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->filter_valid ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "filter_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_fix
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->gnss_fix ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_fix", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // no_rotation_update_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->no_rotation_update_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "no_rotation_update_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // representative_motion
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->representative_motion ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "representative_motion", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clock_bias_estimation
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clock_bias_estimation ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clock_bias_estimation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_acc_x
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_acc_x ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_acc_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_acc_y
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_acc_y ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_acc_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_acc_z
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_acc_z ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_acc_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_gyr_x
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_gyr_x ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_gyr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_gyr_y
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_gyr_y ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_gyr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_gyr_z
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_gyr_z ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_gyr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_mag_x
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_mag_x ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_mag_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_mag_y
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_mag_y ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_mag_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipflag_mag_z
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipflag_mag_z ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipflag_mag_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // clipping_indication
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->clipping_indication ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clipping_indication", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // syncin_marker
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->syncin_marker ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "syncin_marker", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // syncout_marker
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->syncout_marker ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "syncout_marker", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // filter_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->filter_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "filter_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // have_gnss_time_pulse
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->have_gnss_time_pulse ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "have_gnss_time_pulse", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtk_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rtk_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtk_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
