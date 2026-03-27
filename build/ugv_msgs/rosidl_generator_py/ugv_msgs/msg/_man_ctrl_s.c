// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ugv_msgs:msg/ManCtrl.idl
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
#include "ugv_msgs/msg/detail/man_ctrl__struct.h"
#include "ugv_msgs/msg/detail/man_ctrl__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ugv_msgs__msg__man_ctrl__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[31];
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
    assert(strncmp("ugv_msgs.msg._man_ctrl.ManCtrl", full_classname_dest, 30) == 0);
  }
  ugv_msgs__msg__ManCtrl * ros_message = _ros_message;
  {  // auto_en
    PyObject * field = PyObject_GetAttrString(_pymsg, "auto_en");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->auto_en = (Py_True == field);
    Py_DECREF(field);
  }
  {  // linear_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "linear_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->linear_vel = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // steer_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "steer_cmd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->steer_cmd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // arm_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "arm_cmd");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
      Py_ssize_t size = 5;
      float * dest = ros_message->arm_cmd;
      for (Py_ssize_t i = 0; i < size; ++i) {
        float tmp = *(npy_float32 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(float));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ugv_msgs__msg__man_ctrl__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ManCtrl */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ugv_msgs.msg._man_ctrl");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ManCtrl");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ugv_msgs__msg__ManCtrl * ros_message = (ugv_msgs__msg__ManCtrl *)raw_ros_message;
  {  // auto_en
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->auto_en ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "auto_en", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // linear_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->linear_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "linear_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // steer_cmd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->steer_cmd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steer_cmd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // arm_cmd
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "arm_cmd");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT32);
    assert(sizeof(npy_float32) == sizeof(float));
    npy_float32 * dst = (npy_float32 *)PyArray_GETPTR1(seq_field, 0);
    float * src = &(ros_message->arm_cmd[0]);
    memcpy(dst, src, 5 * sizeof(float));
    Py_DECREF(field);
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
