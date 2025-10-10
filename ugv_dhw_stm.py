
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
from ugv import man_ctrl
from ugv import auto_ctrl

import socket

# Set up the UDP server
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the server to an IP and port 
server_address = ('192.168.20.5', 54321)  # Replace with your server's IP
server_socket.bind(server_address)

# Define the known client IP and port
client_ip = '192.168.20.42'
client_port = 8   

class UgvControlSub:

    @staticmethod
    def process_data(reader):
        # take_data() returns copies of all the data samples in the reader
        # and removes them. To also take the SampleInfo meta-data, use take().
        # To not remove the data from the reader, use read_data() or read().
        samples = reader.take_data()
        #Check if samples is an empty list (indicating that controller is disconnected)
        if (len(samples) != None):
            if samples[0].auto_en == True:
                print("Autonomous Enabled")
                # AUTO_VEL = 0.5
                # STEER_CMD = 0
                # auto_flag = float(samples[0].auto_en)  # Convert boolean flag to float so that it can be properly decoded on the nucleo side
                # udp_payload = f"{AUTO_VEL}, {STEER_CMD}, {auto_flag}".encode()
                # server_socket.sendto(udp_payload, (client_ip, client_port))
                # print(f"Const Vel: {AUTO_VEL}, Const Steer: {STEER_CMD}, Autonomous Flag: {auto_flag}")
            else:
                if(len(samples) != None): 
                    udp_payload = f"{samples[0].arm_cmd[0]}, {samples[0].arm_cmd[1]}, {samples[0].arm_cmd[2]}, {samples[0].arm_cmd[3]}, {samples[0].arm_cmd[4]}".encode()
                    print(len(udp_payload.decode()))
                    server_socket.sendto(udp_payload, (client_ip, client_port))
                    print(f"Elbow:{samples[0].arm_cmd[0]}, Forarm:{samples[0].arm_cmd[1]}, Wrist:{samples[0].arm_cmd[2]}, Rot Base:{samples[0].arm_cmd[3]}, Claw:{samples[0].arm_cmd[4]}")
        else:
            print("Digital HW buffer is empty")
        # for sample in samples:
        #     print(f"Received: {sample}")
        return len(samples)

    @staticmethod
    def run_subscriber(domain_id: int, sample_count: int):

        # A DomainParticipant allows an application to begin communicating in
        # a DDS domain. Typically there is one DomainParticipant per application.
        # DomainParticipant QoS is configured in USER_QOS_PROFILES.xml
        participant = dds.DomainParticipant(domain_id)

        # A Topic has a name and a datatype.
        man_topic = dds.Topic(participant, "man_ctrl", man_ctrl)

        # This DataReader reads data on Topic "Example logger".
        # DataReader QoS is configured in USER_QOS_PROFILES.xml
        reader = dds.DataReader(participant.implicit_subscriber, man_topic)

        # Initialize samples_read to zero
        samples_read = 0

        # Associate a handler with the status condition. This will run when the
        # condition is triggered, in the context of the dispatch call (see below)
        # condition argument is not used
        def condition_handler(_):
            nonlocal samples_read
            nonlocal reader
            samples_read += UgvControlSub.process_data(reader)

        # Obtain the DataReader's Status Condition
        status_condition = dds.StatusCondition(reader)

        # Enable the "data available" status and set the handler.
        status_condition.enabled_statuses = dds.StatusMask.DATA_AVAILABLE
        status_condition.set_handler(condition_handler)

        # Create a WaitSet and attach the StatusCondition
        waitset = dds.WaitSet()
        waitset += status_condition

        while samples_read < sample_count:
            # Catch control-C interrupt
            try:
                # Dispatch will call the handlers associated to the WaitSet conditions
                # when they activate

                waitset.dispatch(dds.Duration(1))  # Wait up to 1s each time
            except KeyboardInterrupt:
                break

        print("preparing to shut down...")


if __name__ == "__main__":
    UgvControlSub.run_subscriber(
            domain_id=0,
            sample_count=sys.maxsize)
