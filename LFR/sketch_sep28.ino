//Code: Arduino Line Follower Robot Car

// Assigning the pins from the Motor Driver pin name , Arduino pin assignment
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5

// Defining the Motor Rotation speeds
int M1_Speed = 80; // speed of motor 1
int M2_Speed = 80; // speed of motor 2
int LeftRotationSpeed = 250;  // Left Rotation Speed
int RightRotationSpeed = 250; // Right Rotation Speed

// Function prototypes for clarity
void forward();
void backward();
void right();
void left();
void stop();

void setup() {
	pinMode(in1,OUTPUT);
	pinMode(in2,OUTPUT);
	pinMode(in3,OUTPUT);
	pinMode(in4,OUTPUT);

	pinMode(enA,OUTPUT);
	pinMode(enB,OUTPUT);

	pinMode(A0, INPUT); // initialize Left sensor as an input
	pinMode(A1, INPUT); // initialize Right sensor as an input
}

void loop() {
	// Read line sensor values
	int LEFT_SENSOR = digitalRead(A0);
   	int RIGHT_SENSOR = digitalRead(A1);
   	if(RIGHT_SENSOR==0 && LEFT_SENSOR==0) {
		forward(); //Moving forward
   	}
   	else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
		right(); //Turn Right
   	}
   	else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
		left(); //Turn Left
   	}
   	else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
		Stop();  //Stopping the device
   	}
}

// Function definitions for robot movements
void forward() {
    // Setting motor directions for forward movement
	digitalWrite(in1, HIGH);
  	digitalWrite(in2, LOW);
  	digitalWrite(in3, HIGH);
  	digitalWrite(in4, LOW);
    
    // Setting motor speeds
  	analogWrite(enA, M1_Speed);
  	analogWrite(enB, M2_Speed);
}

void backward() {
    // Setting motor directions for backward movement
  	digitalWrite(in1, LOW);
  	digitalWrite(in2, HIGH);
  	digitalWrite(in3, LOW);
  	digitalWrite(in4, HIGH);
  
    // Setting motor speeds
  	analogWrite(enA, M1_Speed);
  	analogWrite(enB, M2_Speed);
}

void right() {
    // Setting motor directions for turning right
	digitalWrite(in1, LOW);
  	digitalWrite(in2, HIGH);
  	digitalWrite(in3, HIGH);
  	digitalWrite(in4, LOW);

    // Setting motor speeds for turning right
	analogWrite(enA, LeftRotationSpeed);
	analogWrite(enB, RightRotationSpeed);
}

void left()
{
    // Set motor directions for turning left
  	digitalWrite(in1, HIGH);
  	digitalWrite(in2, LOW);
  	digitalWrite(in3, LOW);
  	digitalWrite(in4, HIGH);

    // Set motor speeds for turning left
  	analogWrite(enA, LeftRotationSpeed);
  	analogWrite(enB, RightRotationSpeed);
}

void Stop()
{
    // Stop all motors
  	digitalWrite(in1, LOW);
  	digitalWrite(in2, LOW);
  	digitalWrite(in3, LOW);
  	digitalWrite(in4, LOW);
}
