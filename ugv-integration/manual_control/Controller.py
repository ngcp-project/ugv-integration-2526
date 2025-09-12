from inputs import devices
for device in devices:
    print(device)

from inputs import get_gamepad
currentY = 0
currentX = 0
while 1:
    events = get_gamepad()
    for event in events:
        if event.code == "ABS_X":
            currentX = event.state
            currentX = currentX*(100/32768)
            print( int(currentX), int(currentY))
        if event.code == "ABS_Y":
            currentY = event.state
            currentY = currentY*(100/32768)
            print( int(currentX), int(currentY))


'''

from inputs import get_gamepad
while 1:
    events = get_gamepad()
    for event in events:
        print(event.ev_type, event.code, event.state)

'''