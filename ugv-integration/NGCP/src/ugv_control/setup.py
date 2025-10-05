from setuptools import setup

package_name = 'ugv_control'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='UGV control node (gamepad → ManCtrl/AutoCtrl)',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'ugv_control_pub = ugv_control.ugv_control_pub:main',
            'ugv_control_sub = ugv_control.ugv_control_sub:main',
        ],
    },
)
