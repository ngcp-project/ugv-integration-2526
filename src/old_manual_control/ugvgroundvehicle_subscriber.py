
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

import socket
class ugvgroundvehicleSubscriber:

    @staticmethod
    def process_data(reader):
        # take_data() returns copies of all the data samples in the reader
        # and removes them. To also take the SampleInfo meta-data, use take().
        # To not remove the data from the reader, use read_data() or read().
        samples = reader.take_data()
        for sample in samples:
            print(f"Received: {sample}")
    
        return len(samples)

    @staticmethod
    def run_subscriber(domain_id: int, sample_count: int):

        # A DomainParticipant allows an application to begin communicating in
        # a DDS domain. Typically there is one DomainParticipant per application.
        # DomainParticipant QoS is configured in USER_QOS_PROFILES.xml
        participant = dds.DomainParticipant(domain_id)

        # A Topic has a name and a datatype.
        topic = dds.Topic(participant, "ugvgroundvehicle", ugvgroundvehicle)

        # This DataReader reads data on Topic "Example ugvgroundvehicle".
        # DataReader QoS is configured in USER_QOS_PROFILES.xml
        reader = dds.DataReader(participant.implicit_subscriber, topic)
        # Set up the UDP server
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        # Bind the server to an IP and port (localhost and port 12345 in this case)
        server_address = ('10.0.2.15', 12345)  # Replace with your server's IP
        server_socket.bind(server_address)

        # Define the known client IP and port
        client_ip = '192.168.20.21'
        client_port = 8   
        # Initialize samples_read to zero
        samples_read = 0

        # Associate a handler with the status condition. This will run when the
        # condition is triggered, in the context of the dispatch call (see below)
        # condition argument is not used
        def condition_handler(_):
            nonlocal samples_read
            nonlocal reader
            samples = reader.take_data()
            print(f"(linear velocity, steering angle): ({samples[0].velocity}, {samples[0].SteeringAngle})")
            #udp_payload = f"(linear velocity, steering angle): ({samples[0].velocity}, {samples[0].SteeringAngle})".encode()
            udp_payload = f"{samples[0].velocity}, {samples[0].SteeringAngle}".encode()
            server_socket.sendto(udp_payload, (client_ip, client_port))
            time.sleep(.1)
            samples_read += ugvgroundvehicleSubscriber.process_data(reader)
            
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
                #print("ugvgroundvehcile subscriber sleeping...")

                waitset.dispatch(dds.Duration(.2))  # Wait up to 1s each time
            except KeyboardInterrupt:
                break

        print("preparing to shut down...")
        server_socket.close()

if __name__ == "__main__":
    ugvgroundvehicleSubscriber.run_subscriber(
            domain_id=0,
            sample_count=sys.maxsize)
