# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ugv_msgs:msg/UGVTelemetry.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UGVTelemetry(type):
    """Metaclass of message 'UGVTelemetry'."""

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
            module = import_type_support('ugv_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ugv_msgs.msg.UGVTelemetry')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ugv_telemetry
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ugv_telemetry
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ugv_telemetry
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ugv_telemetry
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ugv_telemetry

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UGVTelemetry(metaclass=Metaclass_UGVTelemetry):
    """Message class 'UGVTelemetry'."""

    __slots__ = [
        '_speed_fps',
        '_pitch_deg',
        '_yaw_deg',
        '_roll_deg',
        '_altitude_ft',
        '_latitude',
        '_longitude',
    ]

    _fields_and_field_types = {
        'speed_fps': 'float',
        'pitch_deg': 'float',
        'yaw_deg': 'float',
        'roll_deg': 'float',
        'altitude_ft': 'float',
        'latitude': 'double',
        'longitude': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.speed_fps = kwargs.get('speed_fps', float())
        self.pitch_deg = kwargs.get('pitch_deg', float())
        self.yaw_deg = kwargs.get('yaw_deg', float())
        self.roll_deg = kwargs.get('roll_deg', float())
        self.altitude_ft = kwargs.get('altitude_ft', float())
        self.latitude = kwargs.get('latitude', float())
        self.longitude = kwargs.get('longitude', float())

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
        if self.speed_fps != other.speed_fps:
            return False
        if self.pitch_deg != other.pitch_deg:
            return False
        if self.yaw_deg != other.yaw_deg:
            return False
        if self.roll_deg != other.roll_deg:
            return False
        if self.altitude_ft != other.altitude_ft:
            return False
        if self.latitude != other.latitude:
            return False
        if self.longitude != other.longitude:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def speed_fps(self):
        """Message field 'speed_fps'."""
        return self._speed_fps

    @speed_fps.setter
    def speed_fps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_fps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'speed_fps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._speed_fps = value

    @builtins.property
    def pitch_deg(self):
        """Message field 'pitch_deg'."""
        return self._pitch_deg

    @pitch_deg.setter
    def pitch_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pitch_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pitch_deg = value

    @builtins.property
    def yaw_deg(self):
        """Message field 'yaw_deg'."""
        return self._yaw_deg

    @yaw_deg.setter
    def yaw_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_deg = value

    @builtins.property
    def roll_deg(self):
        """Message field 'roll_deg'."""
        return self._roll_deg

    @roll_deg.setter
    def roll_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'roll_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._roll_deg = value

    @builtins.property
    def altitude_ft(self):
        """Message field 'altitude_ft'."""
        return self._altitude_ft

    @altitude_ft.setter
    def altitude_ft(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'altitude_ft' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'altitude_ft' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._altitude_ft = value

    @builtins.property
    def latitude(self):
        """Message field 'latitude'."""
        return self._latitude

    @latitude.setter
    def latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'latitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._latitude = value

    @builtins.property
    def longitude(self):
        """Message field 'longitude'."""
        return self._longitude

    @longitude.setter
    def longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'longitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._longitude = value
