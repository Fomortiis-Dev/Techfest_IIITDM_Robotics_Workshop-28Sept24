# Line following robot

This code controls a robot car equipped with two line sensors and motors. The goal is to make the robot follow a black line on a white surface.

## Pin Assignments:
 - ```in1```, ```in2```, ```in3```, ```in4```: Control the direction of the motors.
 - ```enA```, ```enB```: Control the speed of the motors.
 - ```A0```, ```A1```: Connected to the line sensors.

## Motor Control:
 - ```forward()```: Makes the robot move forward.
 - ```backward()```: Makes the robot move backward.
 - ```right()```: Turns the robot right.
 - ```left()```: Turns the robot left.
 - ```stop()```: Stops the robot.

## Line Sensor Readings:
```LEFT_SENSOR``` and ```RIGHT_SENSOR```: Store the values read from the line sensors.

## Robot Behavior:
The ```loop()``` function continuously checks the line sensor readings.
Based on the sensor readings, the robot decides whether to move forward, turn right, turn left, or stop.

## How it Works:
  The ```setup()``` function initializes the pins for the motors and line sensors.
  The ```loop()``` function reads the line sensor values.
  If both sensors are on white, the robot moves forward.
  If only the right sensor is on white, the robot turns left.
  If only the left sensor is on white, the robot turns right.
  If both sensors are on black, the robot stops.

## Key Points:
The code uses a simple algorithm to follow the line.The motor speeds and turning angles can be adjusted to fine-tune the robot's behavior. The code can be extended to include additional features like obstacle avoidance or more complex line-following algorithms.
