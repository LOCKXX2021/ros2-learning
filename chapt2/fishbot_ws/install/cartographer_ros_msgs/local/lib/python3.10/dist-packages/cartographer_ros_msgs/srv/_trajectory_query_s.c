// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cartographer_ros_msgs:srv/TrajectoryQuery.idl
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
#include "cartographer_ros_msgs/srv/detail/trajectory_query__struct.h"
#include "cartographer_ros_msgs/srv/detail/trajectory_query__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cartographer_ros_msgs__srv__trajectory_query__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("cartographer_ros_msgs.srv._trajectory_query.TrajectoryQuery_Request", full_classname_dest, 67) == 0);
  }
  cartographer_ros_msgs__srv__TrajectoryQuery_Request * ros_message = _ros_message;
  {  // trajectory_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trajectory_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cartographer_ros_msgs__srv__trajectory_query__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TrajectoryQuery_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cartographer_ros_msgs.srv._trajectory_query");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TrajectoryQuery_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cartographer_ros_msgs__srv__TrajectoryQuery_Request * ros_message = (cartographer_ros_msgs__srv__TrajectoryQuery_Request *)raw_ros_message;
  {  // trajectory_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->trajectory_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "cartographer_ros_msgs/srv/detail/trajectory_query__struct.h"
// already included above
// #include "cartographer_ros_msgs/srv/detail/trajectory_query__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// end nested array functions include
bool cartographer_ros_msgs__msg__status_response__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * cartographer_ros_msgs__msg__status_response__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_stamped__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cartographer_ros_msgs__srv__trajectory_query__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[69];
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
    assert(strncmp("cartographer_ros_msgs.srv._trajectory_query.TrajectoryQuery_Response", full_classname_dest, 68) == 0);
  }
  cartographer_ros_msgs__srv__TrajectoryQuery_Response * ros_message = _ros_message;
  {  // status
    PyObject * field = PyObject_GetAttrString(_pymsg, "status");
    if (!field) {
      return false;
    }
    if (!cartographer_ros_msgs__msg__status_response__convert_from_py(field, &ros_message->status)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'trajectory'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!geometry_msgs__msg__PoseStamped__Sequence__init(&(ros_message->trajectory), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create geometry_msgs__msg__PoseStamped__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    geometry_msgs__msg__PoseStamped * dest = ros_message->trajectory.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!geometry_msgs__msg__pose_stamped__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cartographer_ros_msgs__srv__trajectory_query__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TrajectoryQuery_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cartographer_ros_msgs.srv._trajectory_query");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TrajectoryQuery_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cartographer_ros_msgs__srv__TrajectoryQuery_Response * ros_message = (cartographer_ros_msgs__srv__TrajectoryQuery_Response *)raw_ros_message;
  {  // status
    PyObject * field = NULL;
    field = cartographer_ros_msgs__msg__status_response__convert_to_py(&ros_message->status);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trajectory
    PyObject * field = NULL;
    size_t size = ros_message->trajectory.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    geometry_msgs__msg__PoseStamped * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->trajectory.data[i]);
      PyObject * pyitem = geometry_msgs__msg__pose_stamped__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
