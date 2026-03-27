// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ugv_msgs:msg/AutoCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__AUTO_CTRL__STRUCT_HPP_
#define UGV_MSGS__MSG__DETAIL__AUTO_CTRL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ugv_msgs__msg__AutoCtrl __attribute__((deprecated))
#else
# define DEPRECATED__ugv_msgs__msg__AutoCtrl __declspec(deprecated)
#endif

namespace ugv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AutoCtrl_
{
  using Type = AutoCtrl_<ContainerAllocator>;

  explicit AutoCtrl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->auto_en = false;
      this->heading_error = 0.0f;
    }
  }

  explicit AutoCtrl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->auto_en = false;
      this->heading_error = 0.0f;
    }
  }

  // field types and members
  using _auto_en_type =
    bool;
  _auto_en_type auto_en;
  using _heading_error_type =
    float;
  _heading_error_type heading_error;

  // setters for named parameter idiom
  Type & set__auto_en(
    const bool & _arg)
  {
    this->auto_en = _arg;
    return *this;
  }
  Type & set__heading_error(
    const float & _arg)
  {
    this->heading_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ugv_msgs::msg::AutoCtrl_<ContainerAllocator> *;
  using ConstRawPtr =
    const ugv_msgs::msg::AutoCtrl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ugv_msgs::msg::AutoCtrl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ugv_msgs::msg::AutoCtrl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ugv_msgs__msg__AutoCtrl
    std::shared_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ugv_msgs__msg__AutoCtrl
    std::shared_ptr<ugv_msgs::msg::AutoCtrl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AutoCtrl_ & other) const
  {
    if (this->auto_en != other.auto_en) {
      return false;
    }
    if (this->heading_error != other.heading_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const AutoCtrl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AutoCtrl_

// alias to use template instance with default allocator
using AutoCtrl =
  ugv_msgs::msg::AutoCtrl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ugv_msgs

#endif  // UGV_MSGS__MSG__DETAIL__AUTO_CTRL__STRUCT_HPP_
