// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
// generated code does not contain a copyright notice
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__rosidl_typesupport_fastrtps_cpp.hpp"
#include "xsens_mti_ros2_driver/msg/detail/xs_status_word__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace xsens_mti_ros2_driver
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
cdr_serialize(
  const xsens_mti_ros2_driver::msg::XsStatusWord & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: selftest
  cdr << (ros_message.selftest ? true : false);
  // Member: filter_valid
  cdr << (ros_message.filter_valid ? true : false);
  // Member: gnss_fix
  cdr << (ros_message.gnss_fix ? true : false);
  // Member: no_rotation_update_status
  cdr << ros_message.no_rotation_update_status;
  // Member: representative_motion
  cdr << (ros_message.representative_motion ? true : false);
  // Member: clock_bias_estimation
  cdr << (ros_message.clock_bias_estimation ? true : false);
  // Member: clipflag_acc_x
  cdr << (ros_message.clipflag_acc_x ? true : false);
  // Member: clipflag_acc_y
  cdr << (ros_message.clipflag_acc_y ? true : false);
  // Member: clipflag_acc_z
  cdr << (ros_message.clipflag_acc_z ? true : false);
  // Member: clipflag_gyr_x
  cdr << (ros_message.clipflag_gyr_x ? true : false);
  // Member: clipflag_gyr_y
  cdr << (ros_message.clipflag_gyr_y ? true : false);
  // Member: clipflag_gyr_z
  cdr << (ros_message.clipflag_gyr_z ? true : false);
  // Member: clipflag_mag_x
  cdr << (ros_message.clipflag_mag_x ? true : false);
  // Member: clipflag_mag_y
  cdr << (ros_message.clipflag_mag_y ? true : false);
  // Member: clipflag_mag_z
  cdr << (ros_message.clipflag_mag_z ? true : false);
  // Member: clipping_indication
  cdr << (ros_message.clipping_indication ? true : false);
  // Member: syncin_marker
  cdr << (ros_message.syncin_marker ? true : false);
  // Member: syncout_marker
  cdr << (ros_message.syncout_marker ? true : false);
  // Member: filter_mode
  cdr << ros_message.filter_mode;
  // Member: have_gnss_time_pulse
  cdr << (ros_message.have_gnss_time_pulse ? true : false);
  // Member: rtk_status
  cdr << ros_message.rtk_status;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  xsens_mti_ros2_driver::msg::XsStatusWord & ros_message)
{
  // Member: selftest
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.selftest = tmp ? true : false;
  }

  // Member: filter_valid
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.filter_valid = tmp ? true : false;
  }

  // Member: gnss_fix
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.gnss_fix = tmp ? true : false;
  }

  // Member: no_rotation_update_status
  cdr >> ros_message.no_rotation_update_status;

  // Member: representative_motion
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.representative_motion = tmp ? true : false;
  }

  // Member: clock_bias_estimation
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clock_bias_estimation = tmp ? true : false;
  }

  // Member: clipflag_acc_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_acc_x = tmp ? true : false;
  }

  // Member: clipflag_acc_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_acc_y = tmp ? true : false;
  }

  // Member: clipflag_acc_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_acc_z = tmp ? true : false;
  }

  // Member: clipflag_gyr_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_gyr_x = tmp ? true : false;
  }

  // Member: clipflag_gyr_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_gyr_y = tmp ? true : false;
  }

  // Member: clipflag_gyr_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_gyr_z = tmp ? true : false;
  }

  // Member: clipflag_mag_x
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_mag_x = tmp ? true : false;
  }

  // Member: clipflag_mag_y
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_mag_y = tmp ? true : false;
  }

  // Member: clipflag_mag_z
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipflag_mag_z = tmp ? true : false;
  }

  // Member: clipping_indication
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.clipping_indication = tmp ? true : false;
  }

  // Member: syncin_marker
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.syncin_marker = tmp ? true : false;
  }

  // Member: syncout_marker
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.syncout_marker = tmp ? true : false;
  }

  // Member: filter_mode
  cdr >> ros_message.filter_mode;

  // Member: have_gnss_time_pulse
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.have_gnss_time_pulse = tmp ? true : false;
  }

  // Member: rtk_status
  cdr >> ros_message.rtk_status;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
get_serialized_size(
  const xsens_mti_ros2_driver::msg::XsStatusWord & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: selftest
  {
    size_t item_size = sizeof(ros_message.selftest);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: filter_valid
  {
    size_t item_size = sizeof(ros_message.filter_valid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gnss_fix
  {
    size_t item_size = sizeof(ros_message.gnss_fix);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: no_rotation_update_status
  {
    size_t item_size = sizeof(ros_message.no_rotation_update_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: representative_motion
  {
    size_t item_size = sizeof(ros_message.representative_motion);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clock_bias_estimation
  {
    size_t item_size = sizeof(ros_message.clock_bias_estimation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_acc_x
  {
    size_t item_size = sizeof(ros_message.clipflag_acc_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_acc_y
  {
    size_t item_size = sizeof(ros_message.clipflag_acc_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_acc_z
  {
    size_t item_size = sizeof(ros_message.clipflag_acc_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_gyr_x
  {
    size_t item_size = sizeof(ros_message.clipflag_gyr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_gyr_y
  {
    size_t item_size = sizeof(ros_message.clipflag_gyr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_gyr_z
  {
    size_t item_size = sizeof(ros_message.clipflag_gyr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_mag_x
  {
    size_t item_size = sizeof(ros_message.clipflag_mag_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_mag_y
  {
    size_t item_size = sizeof(ros_message.clipflag_mag_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipflag_mag_z
  {
    size_t item_size = sizeof(ros_message.clipflag_mag_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: clipping_indication
  {
    size_t item_size = sizeof(ros_message.clipping_indication);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: syncin_marker
  {
    size_t item_size = sizeof(ros_message.syncin_marker);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: syncout_marker
  {
    size_t item_size = sizeof(ros_message.syncout_marker);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: filter_mode
  {
    size_t item_size = sizeof(ros_message.filter_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: have_gnss_time_pulse
  {
    size_t item_size = sizeof(ros_message.have_gnss_time_pulse);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rtk_status
  {
    size_t item_size = sizeof(ros_message.rtk_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_xsens_mti_ros2_driver
max_serialized_size_XsStatusWord(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: selftest
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: filter_valid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: gnss_fix
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: no_rotation_update_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: representative_motion
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clock_bias_estimation
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_acc_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_acc_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_acc_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_gyr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_gyr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_gyr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_mag_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_mag_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipflag_mag_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: clipping_indication
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: syncin_marker
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: syncout_marker
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: filter_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: have_gnss_time_pulse
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rtk_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = xsens_mti_ros2_driver::msg::XsStatusWord;
    is_plain =
      (
      offsetof(DataType, rtk_status) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _XsStatusWord__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const xsens_mti_ros2_driver::msg::XsStatusWord *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _XsStatusWord__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<xsens_mti_ros2_driver::msg::XsStatusWord *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _XsStatusWord__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const xsens_mti_ros2_driver::msg::XsStatusWord *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _XsStatusWord__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_XsStatusWord(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _XsStatusWord__callbacks = {
  "xsens_mti_ros2_driver::msg",
  "XsStatusWord",
  _XsStatusWord__cdr_serialize,
  _XsStatusWord__cdr_deserialize,
  _XsStatusWord__get_serialized_size,
  _XsStatusWord__max_serialized_size
};

static rosidl_message_type_support_t _XsStatusWord__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_XsStatusWord__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace xsens_mti_ros2_driver

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_xsens_mti_ros2_driver
const rosidl_message_type_support_t *
get_message_type_support_handle<xsens_mti_ros2_driver::msg::XsStatusWord>()
{
  return &xsens_mti_ros2_driver::msg::typesupport_fastrtps_cpp::_XsStatusWord__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, xsens_mti_ros2_driver, msg, XsStatusWord)() {
  return &xsens_mti_ros2_driver::msg::typesupport_fastrtps_cpp::_XsStatusWord__handle;
}

#ifdef __cplusplus
}
#endif
