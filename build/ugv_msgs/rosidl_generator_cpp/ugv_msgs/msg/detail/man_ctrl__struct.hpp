// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ugv_msgs:msg/ManCtrl.idl
// generated code does not contain a copyright notice

#ifndef UGV_MSGS__MSG__DETAIL__MAN_CTRL__STRUCT_HPP_
#define UGV_MSGS__MSG__DETAIL__MAN_CTRL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ugv_msgs__msg__ManCtrl __attribute__((deprecated))
#else
# define DEPRECATED__ugv_msgs__msg__ManCtrl __declspec(deprecated)
#endif

namespace ugv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ManCtrl_
{
  using Type = ManCtrl_<ContainerAllocator>;

  explicit ManCtrl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->auto_en = false;
      this->linear_vel = 0.0f;
      this->steer_cmd = 0.0f;
      std::fill<typename std::array<float, 5>::iterator, float>(this->arm_cmd.begin(), this->arm_cmd.end(), 0.0f);
    }
  }

  explicit ManCtrl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : arm_cmd(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->auto_en = false;
      this->linear_vel = 0.0f;
      this->steer_cmd = 0.0f;
      std::fill<typename std::array<float, 5>::iterator, float>(this->arm_cmd.begin(), this->arm_cmd.end(), 0.0f);
    }
  }

  // field types and members
  using _auto_en_type =
    bool;
  _auto_en_type auto_en;
  using _linear_vel_type =
    float;
  _linear_vel_type linear_vel;
  using _steer_cmd_type =
    float;
  _steer_cmd_type steer_cmd;
  using _arm_cmd_type =
    std::array<float, 5>;
  _arm_cmd_type arm_cmd;

  // setters for named parameter idiom
  Type & set__auto_en(
    const bool & _arg)
  {
    this->auto_en = _arg;
    return *this;
  }
  Type & set__linear_vel(
    const float & _arg)
  {
    this->linear_vel = _arg;
    return *this;
  }
  Type & set__steer_cmd(
    const float & _arg)
  {
    this->steer_cmd = _arg;
    return *this;
  }
  Type & set__arm_cmd(
    const std::array<float, 5> & _arg)
  {
    this->arm_cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ugv_msgs::msg::ManCtrl_<ContainerAllocator> *;
  using ConstRawPtr =
    const ugv_msgs::msg::ManCtrl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ugv_msgs::msg::ManCtrl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ugv_msgs::msg::ManCtrl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ugv_msgs__msg__ManCtrl
    std::shared_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ugv_msgs__msg__ManCtrl
    std::shared_ptr<ugv_msgs::msg::ManCtrl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ManCtrl_ & other) const
  {
    if (this->auto_en != other.auto_en) {
      return false;
    }
    if (this->linear_vel != other.linear_vel) {
      return false;
    }
    if (this->steer_cmd != other.steer_cmd) {
      return false;
    }
    if (this->arm_cmd != other.arm_cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const ManCtrl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ManCtrl_

// alias to use template instance with default allocator
using ManCtrl =
  ugv_msgs::msg::ManCtrl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ugv_msgs

#endif  // UGV_MSGS__MSG__DETAIL__MAN_CTRL__STRUCT_HPP_
