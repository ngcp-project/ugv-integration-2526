from setuptools import setup

package_name = 'ugv_nav'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/xsens_nav.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ugv',
    maintainer_email='todo@todo.com',
    description='UGV navigation with Xsens GPS + Dubins path planning',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'xsens_subscriber = ugv_nav.xsens_subscriber:main',
        ],
    },
)
