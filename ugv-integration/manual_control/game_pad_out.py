## This program prints the output of an xbox controller to stdout

from inputs import get_gamepad
import pdb
from time import sleep
lin_vel = 0
steering_angle = 0

while 1:
    #breakpoint()    
    events_1 = get_gamepad()
    if events_1[0].code == "ABS_Y":
        lin_vel = events_1[0].state

    events_2 = get_gamepad()
    if events_2[0].code == "ABS_X": 
        steering_angle = events_2[0].state
    
    print(f"(lin_vel, steering_angle): ({lin_vel}, {steering_angle})")
    

    #events = get_gamepad()
    #print(f"({events[0].code}), ({events[0].state})")
    #for event in events:V
  #      print(event.ev_type, event.code)
    #     print(event.state)
