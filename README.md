# Integration Resources:

## DDS Resources:      
RTI Connext Manual* : https://community.rti.com/static/documentation/connext-dds/7.3.0/doc/manuals/connext_dds_professional/getting_started_guide/cpp11/before.html

Shapes Demo* : https://www.youtube.com/watch?v=A9cTANTnqSY

"Hello World" Demo : https://www.youtube.com/watch?v=76lqc1CRMRU

RTI Connext Overview: https://www.youtube.com/watch?v=3W0eTaBLi0E


## Programming Basics:   
Python Introduction : https://www.youtube.com/watch?v=ix9cRaBkVe0

C++ Introduction* : https://www.youtube.com/watch?v=-TkoO8Z07hI

## Hardware:
NVIDIA Jetson Orin Nano SBC Introduction: https://developer.nvidia.com/embedded/learn/jetson-orin-nano-devkit-user-guide/software_setup.html

## Software:
Markdown Tutorial* : https://www.markdownguide.org/basic-syntax/

Wireshark Introduction* (our network analysis and debugging tool) : https://www.youtube.com/watch?v=lb1Dw0elw0Q&t=68s

## *IMPORTANT!


## How to run XBees

1) install the requirements 
    pip install -r requirements.txt
    pip install -e .

2) Find the serial ports for both controller and jetson
    on jetson 
        * To see what appears when you plug in the device:
```bash 
dmesg -w
```

3) Send commands from the GCS and run the launcher on the Jetson

* on the Jetson side
      ros2 launch ugv_comms ugv_all.launch.py

### It launches all three (xsens driver on USB2, data conversion, and XBee comms on USB3 with your MAC addresses hardcoded as defaults). You can still override if needed:

  ros2 launch ugv_comms ugv_all.launch.py xbee_port:=/dev/ttyUSB1


* On GCS:
	Run commands automatically:
		python scripts/gcs_command_simulator.py --xbee-port COM3 --vehicle-mac 0013A20042839F3E
	Run commands manually:
		python scripts/gcs_command_manual.py --xbee-port COM3 --vehicle-mac 0013A20042839F3E

