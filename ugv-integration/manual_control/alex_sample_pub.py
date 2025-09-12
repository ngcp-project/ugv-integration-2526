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



class ugvgroundvehiclePublisher:

    @staticmethod
    def run_publisher(domain_id: int, sample_count: int):

        # A DomainParticipant allows an application to begin communicating in
        # a DDS domain. Typically there is one DomainParticipant per application.
        # DomainParticipant QoS is configured in USER_QOS_PROFILES.xml
        participant = dds.DomainParticipant(domain_id)

        # A Topic has a name and a datatype.
        topic = dds.Topic(participant, "Example ugvgroundvehicle", ugvgroundvehicle)

        # This DataWriter will write data on Topic "Example ugvgroundvehicle"
        # DataWriter QoS is configured in USER_QOS_PROFILES.xml
        writer = dds.DataWriter(participant.implicit_publisher, topic)
        sample = ugvgroundvehicle()


        currentY = 0
        currentX = 0

        for count in range(sample_count):
            # Catch control-C interrupt
            try:
                # Modify the data to be sent here

                events = get_gamepad()
                for event in events:
                    if event.code == "ABS_X":
                        currentX = event.state
                        currentX = currentX*(100/32768)
                        print( int(currentX), int(currentY))
                        sample.SteeringAngle = int(currentX)
                        sample.velocity = int(currentY)
                    if event.code == "ABS_Y":
                        currentY = event.state
                        currentY = currentY*(100/32768)
                        print( int(currentX), int(currentY))
                        sample.SteeringAngle = int(currentX)
                        sample.velocity = int(currentY)



                print(f"Writing ugvgroundvehicle, count {count}")
                writer.write(sample)
                time.sleep(0.02)
            except KeyboardInterrupt:
                break

        print("preparing to shut down...")




'''

from inputs import get_gamepad
while 1:
    events = get_gamepad()
    for event in events:
        print(event.ev_type, event.code, event.state)
'''


if __name__ == "__main__":
    ugvgroundvehiclePublisher.run_publisher(
            domain_id=0,
            sample_count=sys.maxsize)
