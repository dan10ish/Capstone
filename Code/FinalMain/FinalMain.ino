#include <Servo.h>
Servo s1;
Servo s2;                          // create servo object to control a servo
Servo s3;                          // create servo object to control a servo                          
Servo s4;                          // create servo object to control a servo

int posn = 0;

int motor1pin1 = 11;
int motor1pin2 = 10;

int motor2pin1 = 9;
int motor2pin2 = 8;

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  // Initialize any other necessary setup code here
  s1.attach (2);      
  s2.attach (3);      
  s3.attach (6);      
  s4.attach (4);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  analogWrite(12, 255);
  analogWrite(7, 255);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
  // Continue with other tasks in your main loop
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      digitalWrite(motor1pin1,  HIGH);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      break;
    case BACKWARD:
      // Perform action for moving backward
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
      break;
    case LEFT:
      // Perform action for turning left
      
      /*
      s3.write(50);
      delay(3000);
      s4.write(0);*/
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      break;
    case RIGHT:
      // Perform action for turning right
      /*
      s3.write(50);
      delay(3000);
      s4.write(180);*/
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
      break;
    case CIRCLE:
      // Perform action for Close
      s1.write(90);
      s2.write(0);
      break;
    case CROSS:
      // Perform action for immediate stop or crossing
      s3.write(10);
      break;
    case TRIANGLE:
      // Perform action for toggling a state (e.g., LED on/off)
      s3.write(160);
      break;
    case SQUARE:
      // Perform action for Pick Up
      s1.write(0);
      s2.write(90);
      break;
    case START:
      // Perform action for starting a process or operation
      break;
    case PAUSE:
      // Perform action for pausing a process or operation
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      break;
    default:
      break;
  }
}