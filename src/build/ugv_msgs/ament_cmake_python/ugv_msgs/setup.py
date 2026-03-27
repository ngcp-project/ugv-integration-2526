from setuptools import find_packages
from setuptools import setup

setup(
    name='ugv_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('ugv_msgs', 'ugv_msgs.*')),
)
