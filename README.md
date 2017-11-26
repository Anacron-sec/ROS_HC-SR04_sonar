# ROS_HC-SR04_sonar
Arduino sketch that makes HC-SR04 sonar publish distance in ROS (Robot Operating System)
Author an4cr0n

## Usage

First run ros core:
```
roscore
```

then connect to arduino with rosserial_python on the specified interface, something like /dev/ttyACM0 or /dev/ttyUSB0 (N.B. is not installed by default, refer to ROS wiki):
```
rosrun rosserial_python serial_node.py /dev/[interface]
```

to test if it works try:
```
rostopic echo /sonar
```
