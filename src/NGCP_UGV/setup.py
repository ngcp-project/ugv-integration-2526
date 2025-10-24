from setuptools import setup

package_name = 'ngcp_ugv'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lev',
    maintainer_email='levonmalkhasian@gmail.com',
    description='UGV Control Node',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'ugv_control_pub = ngcp_ugv.ugv_control_pub:main',
            'ugv_control_sub = ngcp_ugv.ugv_control_sub:main',
        ],
    },
)