
# (c) Copyright, Real-Time Innovations, 2022.  All rights reserved.
# RTI grants Licensee a license to use, modify, compile, and create derivative
# works of the software solely for use with RTI Connext DDS. Licensee may
# redistribute copies of the software provided that all such copies are subject
# to this license. The software is provided "as is", with no warranty of any
# type, including any warranty for fitness for any purpose. RTI is under no
# obligation to maintain or support the software. RTI shall not be liable for
# any incidental or consequential damages arising out of the use or inability
# to use the software.

import time
import sys
import rti.connextdds as dds
from ugvgroundvehicle import ugvgroundvehicle
from inputs import get_gamepad


SCALE_FACTOR = -327
MAX_JOY_VAL = 2**15 # max input of 32,768
#velocity = 0 # linear velocity Y
#angle = 0 # steering angle X

class ugvgroundvehiclePublisher:
    @staticmethod
    def run_publisher(domain_id: int, sample_count: int):
        # A DomainParticipant allows an application to begin communicating in
        # a DDS domain. Typically there is one DomainParticipant per application.
        # DomainParticipant QoS is configured in USER_QOS_PROFILES.xml
        participant = dds.DomainParticipant(domain_id)

        # A Topic has a name and a datatype.
        topic = dds.Topic(participant, "ugvgroundvehicle", ugvgroundvehicle)

        # This DataWriter will write data on Topic "Example ugvgroundvehicle"
        # DataWriter QoS is configured in USER_QOS_PROFILES.xml
        writer = dds.DataWriter(participant.implicit_publisher, topic)
        ugv_manual = ugvgroundvehicle()

        for count in range(sample_count):
        # Start of new code
            try:
                event1 = get_gamepad()
                if event1[0].code == 'ABS_Y':
                    ugv_manual.velocity = event1[0].state//SCALE_FACTOR #/ MAX_JOY_VAL

                event2 = get_gamepad()
                if event2[0].code == 'ABS_X':
                    ugv_manual.SteeringAngle = event2[0].state//SCALE_FACTOR  #/ MAX_JOY_VAL
                
                print(f"Linear Velocity: {ugv_manual.velocity}, Steering Angle: {ugv_manual.SteeringAngle}")
                writer.write(ugv_manual)
                #time.sleep(0.02)
            
            except KeyboardInterrupt:
                break			
        print("Preparing to shut down...")
	
if __name__ == "__main__":
    ugvgroundvehiclePublisher.run_publisher(
            domain_id=0,
            sample_count=sys.maxsize)
