 
# Animatronics

Arduino sketch and Python code to control facial expressions of a puppet with servos. A USB-HID game controller (super NES like) is plugged to the computer. The python code running on the computer interprets the commands and send them to the arduino via serial protocol using Xbee radios. The arduino sketch checks the serial port on every iteration of the main loop and updates the position of the servo motors based on what is received.

## Arduino sketch
The Arduino sketch is inside the XBee_Remote_Control_servo. It basically reads the serial port and increments position of the servo motors with the arduino servo library. Nothing fancy except the incremental movement of the servos which was a little tricky.

## Python code
This is the usbHID.py file. It reads in commands from the USB-HID game controller using the [pywinusb library](https://pypi.python.org/pypi/pywinusb/#installation-instructions). It interprets the commands and sends instructions on the serial port. The instructions are forwarded to the arduino through Xbee radio protocol.
