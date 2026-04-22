// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from xsens_mti_ros2_driver:msg/ShipMotion.idl
// generated code does not contain a copyright notice

#ifndef XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__STRUCT_HPP_
#define XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__xsens_mti_ros2_driver__msg__ShipMotion __attribute__((deprecated))
#else
# define DEPRECATED__xsens_mti_ros2_driver__msg__ShipMotion __declspec(deprecated)
#endif

namespace xsens_mti_ros2_driver
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ShipMotion_
{
  using Type = ShipMotion_<ContainerAllocator>;

  explicit ShipMotion_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heave_position = 0.0;
      this->heave_period = 0.0;
    }
  }

  explicit ShipMotion_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->heave_position = 0.0;
      this->heave_period = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _heave_position_type =
    double;
  _heave_position_type heave_position;
  using _heave_period_type =
    double;
  _heave_period_type heave_period;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__heave_position(
    const double & _arg)
  {
    this->heave_position = _arg;
    return *this;
  }
  Type & set__heave_period(
    const double & _arg)
  {
    this->heave_period = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator> *;
  using ConstRawPtr =
    const xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__xsens_mti_ros2_driver__msg__ShipMotion
    std::shared_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__xsens_mti_ros2_driver__msg__ShipMotion
    std::shared_ptr<xsens_mti_ros2_driver::msg::ShipMotion_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ShipMotion_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->heave_position != other.heave_position) {
      return false;
    }
    if (this->heave_period != other.heave_period) {
      return false;
    }
    return true;
  }
  bool operator!=(const ShipMotion_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ShipMotion_

// alias to use template instance with default allocator
using ShipMotion =
  xsens_mti_ros2_driver::msg::ShipMotion_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace xsens_mti_ros2_driver

#endif  // XSENS_MTI_ROS2_DRIVER__MSG__DETAIL__SHIP_MOTION__STRUCT_HPP_
