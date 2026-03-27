from setuptools import find_packages
from setuptools import setup

setup(
    name='xsens_mti_ros2_driver',
    version='1.0.2',
    packages=find_packages(
        include=('xsens_mti_ros2_driver', 'xsens_mti_ros2_driver.*')),
)
