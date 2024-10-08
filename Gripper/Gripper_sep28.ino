#include <Servo.h>

Servo motor_1;      
Servo motor_2;
Servo motor_3;

//#define enA 9  //Enable1 L298 Pin enA 
#define in1 7 //Motor1  L298 Pin in1 
#define in2 8 //Motor1  L298 Pin in1 
#define in3 12 //Motor2  L298 Pin in1 
#define in4 11 //Motor2  L298 Pin in1 
//#define enB 9  //Enable2 L298 Pin enB 

int servo1 = 90;
int servo2 = 0;
int servo3 = 90;

int bt_data;
int Speed = 130;

void setup(){
  
	Serial.begin(9600); // initialize serial communication at 9600 bits per second:
	 
	motor_1.attach(5);   // Waist Servo
	motor_2.attach(6);   // Shoulder Servo
	motor_3.attach(3);   // Gripper Servo
	 
	motor_1.write(servo1); 
	motor_2.write(servo2); 
	motor_3.write(servo3); 

	//pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
	pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
	pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
	pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
	pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
	//pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

	digitalWrite(in1, LOW); //Right Motor forward Pin 
	digitalWrite(in2, LOW); //Right Motor backward Pin 
	digitalWrite(in3, LOW); //Left Motor backward Pin 
	digitalWrite(in4, LOW); //Left Motor forward Pin 

	delay(1000);
}

void loop(){
	//if some date is sent, reads it and saves in state

	if(Serial.available() > 0){     
	bt_data = Serial.read(); 
	Serial.println(bt_data);
	if(bt_data > 20)
	{Speed = bt_data;}      
	}

	//analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
	//analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 


	if(bt_data == 1)
	  {forward(); }  // if the bt_data is '1' the DC motor will go forward
	else if(bt_data == 2)
	  {backward();}  // if the bt_data is '2' the motor will Reverse
	else if(bt_data == 3)
	  {turnLeft();}  // if the bt_data is '3' the motor will turn left
	else if(bt_data == 4)
	  {turnRight();} // if the bt_data is '4' the motor will turn right
	else if(bt_data == 5)
	  {Stop(); }     // if the bt_data '5' the motor will Stop



	else if (bt_data == 8){
	if(servo1<180){servo1 = servo1+1;}
	motor_1.write(servo1);  
	}
	else if (bt_data == 9){
	if(servo1>0){servo1 = servo1-1;} 
	motor_1.write(servo1);  
	}

	else if (bt_data == 10){
	if(servo2>0){servo2 = servo2-1;}
	motor_2.write(servo2);
	}
	else if (bt_data == 11){
	if(servo2<180){servo2 = servo2+1;}
	motor_2.write(servo2);  
	}

	else if (bt_data == 16){
	if(servo3>60){servo3 = servo3-1;}
	motor_3.write(servo3);
	}
	else if (bt_data == 17){
	if(servo3<150){servo3 = servo3+1;}
	motor_3.write(servo3);
	}

	delay(30);
}


void forward(){  //forward
	digitalWrite(in1, HIGH);   //Right Motor forward Pin 
	digitalWrite(in2, LOW);   //Right Motor backward Pin 
	digitalWrite(in3, HIGH);  //Left Motor forward Pin 
	digitalWrite(in4, LOW);   //Left Motor backward Pin 
}

void backward(){ //backward
	digitalWrite(in1, LOW);  
	digitalWrite(in2, HIGH); 
	digitalWrite(in3, LOW); 
	digitalWrite(in4, HIGH);  
}

void turnRight(){ //turnRight
	digitalWrite(in1, LOW);  
	digitalWrite(in2, HIGH);  
	digitalWrite(in3, HIGH);   
	digitalWrite(in4, LOW); 
}

void turnLeft(){ //turnLeft
	digitalWrite(in1, HIGH); 
	digitalWrite(in2, LOW);   
	digitalWrite(in3, LOW); 
	digitalWrite(in4, HIGH);   
}

void Stop(){ //stop
	digitalWrite(in1, LOW); 
	digitalWrite(in2, LOW);  
	digitalWrite(in3, LOW); 
	digitalWrite(in4, LOW); 
}
