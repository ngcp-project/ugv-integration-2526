from setuptools import setup

package_name = 'ugv_comms'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/ugv_comms.launch.py', 'launch/ugv_all.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ugv',
    maintainer_email='todo@todo.com',
    description='XBee command receiver and telemetry bridge for UGV GCS communication',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'xbee_command_receiver = ugv_comms.xbee_command_receiver:main',
        ],
    },
)
