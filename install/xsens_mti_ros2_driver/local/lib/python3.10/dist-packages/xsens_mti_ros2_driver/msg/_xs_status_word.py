# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_mti_ros2_driver:msg/XsStatusWord.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_XsStatusWord(type):
    """Metaclass of message 'XsStatusWord'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('xsens_mti_ros2_driver')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'xsens_mti_ros2_driver.msg.XsStatusWord')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__xs_status_word
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__xs_status_word
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__xs_status_word
            cls._TYPE_SUPPORT = module.type_support_msg__msg__xs_status_word
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__xs_status_word

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class XsStatusWord(metaclass=Metaclass_XsStatusWord):
    """Message class 'XsStatusWord'."""

    __slots__ = [
        '_selftest',
        '_filter_valid',
        '_gnss_fix',
        '_no_rotation_update_status',
        '_representative_motion',
        '_clock_bias_estimation',
        '_clipflag_acc_x',
        '_clipflag_acc_y',
        '_clipflag_acc_z',
        '_clipflag_gyr_x',
        '_clipflag_gyr_y',
        '_clipflag_gyr_z',
        '_clipflag_mag_x',
        '_clipflag_mag_y',
        '_clipflag_mag_z',
        '_clipping_indication',
        '_syncin_marker',
        '_syncout_marker',
        '_filter_mode',
        '_have_gnss_time_pulse',
        '_rtk_status',
    ]

    _fields_and_field_types = {
        'selftest': 'boolean',
        'filter_valid': 'boolean',
        'gnss_fix': 'boolean',
        'no_rotation_update_status': 'uint8',
        'representative_motion': 'boolean',
        'clock_bias_estimation': 'boolean',
        'clipflag_acc_x': 'boolean',
        'clipflag_acc_y': 'boolean',
        'clipflag_acc_z': 'boolean',
        'clipflag_gyr_x': 'boolean',
        'clipflag_gyr_y': 'boolean',
        'clipflag_gyr_z': 'boolean',
        'clipflag_mag_x': 'boolean',
        'clipflag_mag_y': 'boolean',
        'clipflag_mag_z': 'boolean',
        'clipping_indication': 'boolean',
        'syncin_marker': 'boolean',
        'syncout_marker': 'boolean',
        'filter_mode': 'uint8',
        'have_gnss_time_pulse': 'boolean',
        'rtk_status': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.selftest = kwargs.get('selftest', bool())
        self.filter_valid = kwargs.get('filter_valid', bool())
        self.gnss_fix = kwargs.get('gnss_fix', bool())
        self.no_rotation_update_status = kwargs.get('no_rotation_update_status', int())
        self.representative_motion = kwargs.get('representative_motion', bool())
        self.clock_bias_estimation = kwargs.get('clock_bias_estimation', bool())
        self.clipflag_acc_x = kwargs.get('clipflag_acc_x', bool())
        self.clipflag_acc_y = kwargs.get('clipflag_acc_y', bool())
        self.clipflag_acc_z = kwargs.get('clipflag_acc_z', bool())
        self.clipflag_gyr_x = kwargs.get('clipflag_gyr_x', bool())
        self.clipflag_gyr_y = kwargs.get('clipflag_gyr_y', bool())
        self.clipflag_gyr_z = kwargs.get('clipflag_gyr_z', bool())
        self.clipflag_mag_x = kwargs.get('clipflag_mag_x', bool())
        self.clipflag_mag_y = kwargs.get('clipflag_mag_y', bool())
        self.clipflag_mag_z = kwargs.get('clipflag_mag_z', bool())
        self.clipping_indication = kwargs.get('clipping_indication', bool())
        self.syncin_marker = kwargs.get('syncin_marker', bool())
        self.syncout_marker = kwargs.get('syncout_marker', bool())
        self.filter_mode = kwargs.get('filter_mode', int())
        self.have_gnss_time_pulse = kwargs.get('have_gnss_time_pulse', bool())
        self.rtk_status = kwargs.get('rtk_status', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.selftest != other.selftest:
            return False
        if self.filter_valid != other.filter_valid:
            return False
        if self.gnss_fix != other.gnss_fix:
            return False
        if self.no_rotation_update_status != other.no_rotation_update_status:
            return False
        if self.representative_motion != other.representative_motion:
            return False
        if self.clock_bias_estimation != other.clock_bias_estimation:
            return False
        if self.clipflag_acc_x != other.clipflag_acc_x:
            return False
        if self.clipflag_acc_y != other.clipflag_acc_y:
            return False
        if self.clipflag_acc_z != other.clipflag_acc_z:
            return False
        if self.clipflag_gyr_x != other.clipflag_gyr_x:
            return False
        if self.clipflag_gyr_y != other.clipflag_gyr_y:
            return False
        if self.clipflag_gyr_z != other.clipflag_gyr_z:
            return False
        if self.clipflag_mag_x != other.clipflag_mag_x:
            return False
        if self.clipflag_mag_y != other.clipflag_mag_y:
            return False
        if self.clipflag_mag_z != other.clipflag_mag_z:
            return False
        if self.clipping_indication != other.clipping_indication:
            return False
        if self.syncin_marker != other.syncin_marker:
            return False
        if self.syncout_marker != other.syncout_marker:
            return False
        if self.filter_mode != other.filter_mode:
            return False
        if self.have_gnss_time_pulse != other.have_gnss_time_pulse:
            return False
        if self.rtk_status != other.rtk_status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def selftest(self):
        """Message field 'selftest'."""
        return self._selftest

    @selftest.setter
    def selftest(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'selftest' field must be of type 'bool'"
        self._selftest = value

    @builtins.property
    def filter_valid(self):
        """Message field 'filter_valid'."""
        return self._filter_valid

    @filter_valid.setter
    def filter_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'filter_valid' field must be of type 'bool'"
        self._filter_valid = value

    @builtins.property
    def gnss_fix(self):
        """Message field 'gnss_fix'."""
        return self._gnss_fix

    @gnss_fix.setter
    def gnss_fix(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'gnss_fix' field must be of type 'bool'"
        self._gnss_fix = value

    @builtins.property
    def no_rotation_update_status(self):
        """Message field 'no_rotation_update_status'."""
        return self._no_rotation_update_status

    @no_rotation_update_status.setter
    def no_rotation_update_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'no_rotation_update_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'no_rotation_update_status' field must be an unsigned integer in [0, 255]"
        self._no_rotation_update_status = value

    @builtins.property
    def representative_motion(self):
        """Message field 'representative_motion'."""
        return self._representative_motion

    @representative_motion.setter
    def representative_motion(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'representative_motion' field must be of type 'bool'"
        self._representative_motion = value

    @builtins.property
    def clock_bias_estimation(self):
        """Message field 'clock_bias_estimation'."""
        return self._clock_bias_estimation

    @clock_bias_estimation.setter
    def clock_bias_estimation(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clock_bias_estimation' field must be of type 'bool'"
        self._clock_bias_estimation = value

    @builtins.property
    def clipflag_acc_x(self):
        """Message field 'clipflag_acc_x'."""
        return self._clipflag_acc_x

    @clipflag_acc_x.setter
    def clipflag_acc_x(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_acc_x' field must be of type 'bool'"
        self._clipflag_acc_x = value

    @builtins.property
    def clipflag_acc_y(self):
        """Message field 'clipflag_acc_y'."""
        return self._clipflag_acc_y

    @clipflag_acc_y.setter
    def clipflag_acc_y(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_acc_y' field must be of type 'bool'"
        self._clipflag_acc_y = value

    @builtins.property
    def clipflag_acc_z(self):
        """Message field 'clipflag_acc_z'."""
        return self._clipflag_acc_z

    @clipflag_acc_z.setter
    def clipflag_acc_z(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_acc_z' field must be of type 'bool'"
        self._clipflag_acc_z = value

    @builtins.property
    def clipflag_gyr_x(self):
        """Message field 'clipflag_gyr_x'."""
        return self._clipflag_gyr_x

    @clipflag_gyr_x.setter
    def clipflag_gyr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_gyr_x' field must be of type 'bool'"
        self._clipflag_gyr_x = value

    @builtins.property
    def clipflag_gyr_y(self):
        """Message field 'clipflag_gyr_y'."""
        return self._clipflag_gyr_y

    @clipflag_gyr_y.setter
    def clipflag_gyr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_gyr_y' field must be of type 'bool'"
        self._clipflag_gyr_y = value

    @builtins.property
    def clipflag_gyr_z(self):
        """Message field 'clipflag_gyr_z'."""
        return self._clipflag_gyr_z

    @clipflag_gyr_z.setter
    def clipflag_gyr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_gyr_z' field must be of type 'bool'"
        self._clipflag_gyr_z = value

    @builtins.property
    def clipflag_mag_x(self):
        """Message field 'clipflag_mag_x'."""
        return self._clipflag_mag_x

    @clipflag_mag_x.setter
    def clipflag_mag_x(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_mag_x' field must be of type 'bool'"
        self._clipflag_mag_x = value

    @builtins.property
    def clipflag_mag_y(self):
        """Message field 'clipflag_mag_y'."""
        return self._clipflag_mag_y

    @clipflag_mag_y.setter
    def clipflag_mag_y(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_mag_y' field must be of type 'bool'"
        self._clipflag_mag_y = value

    @builtins.property
    def clipflag_mag_z(self):
        """Message field 'clipflag_mag_z'."""
        return self._clipflag_mag_z

    @clipflag_mag_z.setter
    def clipflag_mag_z(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipflag_mag_z' field must be of type 'bool'"
        self._clipflag_mag_z = value

    @builtins.property
    def clipping_indication(self):
        """Message field 'clipping_indication'."""
        return self._clipping_indication

    @clipping_indication.setter
    def clipping_indication(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'clipping_indication' field must be of type 'bool'"
        self._clipping_indication = value

    @builtins.property
    def syncin_marker(self):
        """Message field 'syncin_marker'."""
        return self._syncin_marker

    @syncin_marker.setter
    def syncin_marker(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'syncin_marker' field must be of type 'bool'"
        self._syncin_marker = value

    @builtins.property
    def syncout_marker(self):
        """Message field 'syncout_marker'."""
        return self._syncout_marker

    @syncout_marker.setter
    def syncout_marker(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'syncout_marker' field must be of type 'bool'"
        self._syncout_marker = value

    @builtins.property
    def filter_mode(self):
        """Message field 'filter_mode'."""
        return self._filter_mode

    @filter_mode.setter
    def filter_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'filter_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'filter_mode' field must be an unsigned integer in [0, 255]"
        self._filter_mode = value

    @builtins.property
    def have_gnss_time_pulse(self):
        """Message field 'have_gnss_time_pulse'."""
        return self._have_gnss_time_pulse

    @have_gnss_time_pulse.setter
    def have_gnss_time_pulse(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'have_gnss_time_pulse' field must be of type 'bool'"
        self._have_gnss_time_pulse = value

    @builtins.property
    def rtk_status(self):
        """Message field 'rtk_status'."""
        return self._rtk_status

    @rtk_status.setter
    def rtk_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rtk_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rtk_status' field must be an unsigned integer in [0, 255]"
        self._rtk_status = value
