# Gripper Bot

## Robot Control System:

This code controls a robot equipped with DC motors for movement and servo motors for various actions (e.g., grasping, turning). It receives commands via Bluetooth and executes corresponding actions.

## Motor Control:
 - DC Motors: The ```forward()```, ```backword()```, ```turnRight()```, and ```turnLeft()``` functions control the direction of the DC motors using a L298 motor driver. The Speed variable determines the motor speed (assuming PWM control).
 - Servo Motors: The ```motor_1```, ```motor_2```, and ```motor_3``` Servo objects control the position of the waist, shoulder, and gripper servos, respectively.

## Bluetooth Communication:
  The code continuously checks for incoming Bluetooth data. Received data is interpreted as commands for controlling the robot's movement and actions.

## Key Points:
 - The code provides a foundation for controlling a versatile robot with both DC motors and servo motors.
 - The Bluetooth interface allows for wireless control and customization.
 - The code can be extended to include more complex movement patterns, sensor integration, and advanced features.

## Motor Control Functions:
 - ```forward()```:
    - Sets the direction pins for both motors to move forward.
    - This function assumes that the L298 motor driver is configured correctly for forward motion.
 - ```backward()```:
    - Sets the direction pins for both motors to move backward. Again, this assumes proper configuration of the L298 motor driver.

 - ```turnRight()```:
    - Sets the direction pins to turn the robot right. The specific pin configuration for turning right might vary depending on the motor setup.

 - ```turnLeft()```:
    - Sets the direction pins to turn the robot left. Similar to ```turnRight()```, the pin configuration might need adjustment based on the motor setup.

 - ```Stop()```:
    - Sets all direction pins to low, effectively stopping both motors.

## Servo Control Functions:
 - ```motor_1.write(servo1)```:
     Sets the position of the waist servo to the value stored in servo1. The servo1 variable can be adjusted to control the waist's rotation.

 - ```motor_2.write(servo2)```:
    Sets the position of the shoulder servo to the value stored in servo2. Adjusting servo2 controls the shoulder's movement.

 - ```motor_3.write(servo3)```:
   Sets the position of the gripper servo to the value stored in servo3. Controlling servo3 allows the gripper to open or close.

## Bluetooth Communication Functions:
  - ```Serial.begin(9600)```:
        Initializes serial communication at a baud rate of 9600 bits per second, which is commonly used for Bluetooth communication.

  - ```Serial.available()```:
        Checks if there is any data available to be read from the serial port (Bluetooth).

  - ```Serial.read()```:
        Reads a single byte of data from the serial port and stores it in the bt_data variable.

  - ```Serial.println(bt_data)```:
        Prints the received data to the serial monitor for debugging or monitoring purposes.

These functions collectively enable the robot to respond to Bluetooth commands and perform various actions, such as moving forward, turning, and controlling the servo motors.
