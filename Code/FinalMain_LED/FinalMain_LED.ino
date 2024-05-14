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

#define SOUND_SPEED 0.034

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
#define RELEASE 'Rel'

#define TRIG_PINl 23 
#define ECHO_PINl 22 
int redPinl = 27;    
int greenPinl = 29;  
int bluePinl = 28; 

#define TRIG_PINr 25 
#define ECHO_PINr 24 
int redPinr = 30;    
int greenPinr = 31;  
int bluePinr = 32; 

int buzzerPin = 33;

#define TRIG_PINu 35 
#define ECHO_PINu 34 
int redPinu = 36;    
int greenPinu = 37;  
int bluePinu = 39; 

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  // Initialize any other necessary setup code here
  s1.attach (2);      
  s2.attach (3);      
  s3.attach (6);      
  s4.attach (4);

  pinMode(buzzerPin, OUTPUT);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  analogWrite(12, 255);
  analogWrite(7, 255);

  pinMode(TRIG_PINl, OUTPUT);
  pinMode(ECHO_PINl, INPUT);
  pinMode(TRIG_PINr, OUTPUT);
  pinMode(ECHO_PINr, INPUT);
  pinMode(TRIG_PINu, OUTPUT);
  pinMode(ECHO_PINu, INPUT);

  pinMode(redPinl, OUTPUT);
  pinMode(greenPinl, OUTPUT);
  pinMode(bluePinl, OUTPUT);
  digitalWrite(redPinl, HIGH);
  digitalWrite(greenPinl, HIGH);
  digitalWrite(bluePinl, HIGH);

  pinMode(redPinr, OUTPUT);
  pinMode(greenPinr, OUTPUT);
  pinMode(bluePinr, OUTPUT);
  digitalWrite(redPinr, HIGH);
  digitalWrite(greenPinr, HIGH);
  digitalWrite(bluePinr, HIGH);

  pinMode(redPinu, OUTPUT);
  pinMode(greenPinu, OUTPUT);
  pinMode(bluePinu, OUTPUT);
  digitalWrite(redPinu, HIGH);
  digitalWrite(greenPinu, HIGH);
  digitalWrite(bluePinu, HIGH);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
  // Continue with other tasks in your main loop

  digitalWrite(TRIG_PINl, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PINl, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINl, LOW);
  long durationl = pulseIn(ECHO_PINl, HIGH);
  float distancel = (durationl * SOUND_SPEED) / 2;
  if (distancel < 10){
    setColorl(255, 0, 0);
  }
  else if (distancel > 10 && distancel < 20){
    setColorl(0, 0, 255);
  }
  else {
    setColorl(0,255,0);
  }

  digitalWrite(TRIG_PINu, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PINu, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINu, LOW);
  long durationu = pulseIn(ECHO_PINu, HIGH);
  float distanceu = (durationu * SOUND_SPEED) / 2;
  if (distanceu < 10){
    setColoru(255, 0, 0);
  }
  else if (distanceu > 10 && distanceu < 20){
    setColoru(0, 0, 255);
  }
  else {
    setColoru(0,255,0);
  }

  digitalWrite(TRIG_PINr, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PINr, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINr, LOW);
  long durationr = pulseIn(ECHO_PINr, HIGH);
  float distancer = (durationr * SOUND_SPEED) / 2;
  if (distancer < 10){
    setColorr(255, 0, 0);
  }
  else if (distancer > 10 && distancer < 20){
    setColorr(0, 0, 255);
  }
  else {
    setColorr(0,255,0);
  }

  if (distancel < 10 || distancer < 10 || distanceu < 10){
    digitalWrite(buzzerPin, HIGH);
  }
  else {
    digitalWrite(buzzerPin, LOW);
  }

}

void executeCommand(char command) {
  switch (command) {
    case RELEASE:
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);

      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      break;
    case FORWARD:
      // Perform action for moving forward
      digitalWrite(motor1pin1,   HIGH);
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
      
      s3.write(50);
      delay(2000);
      s4.write(0);
      //digitalWrite(motor1pin1, LOW);
      //digitalWrite(motor1pin2, HIGH);
      //digitalWrite(motor2pin1, HIGH);
      //digitalWrite(motor2pin2, LOW);
      break;
    case RIGHT:
      // Perform action for turning right
      
      s3.write(50);
      delay(2000);
      s4.write(180);
      //digitalWrite(motor1pin1, HIGH);
      //digitalWrite(motor1pin2, LOW);
      //digitalWrite(motor2pin1, LOW);
      //digitalWrite(motor2pin2, HIGH);
      break;
    case CIRCLE:
      // Perform action for Close
      s1.write(90);
      s2.write(0);
      break;
    case CROSS:
      // Perform action for immediate stop or crossing
      s3.write(50);
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

void setColorl(int redValuel, int greenValuel, int blueValuel) {
  // Common anode RGB LED uses inverted logic, LOW is on, HIGH is off
  analogWrite(redPinl, 255 - redValuel);
  analogWrite(greenPinl, 255 - greenValuel);
  analogWrite(bluePinl, 255 - blueValuel);
}

void setColorr(int redValuer, int greenValuer, int blueValuer) {
  // Common anode RGB LED uses inverted logic, LOW is on, HIGH is off
  analogWrite(redPinr, 255 - redValuer);
  analogWrite(greenPinr, 255 - greenValuer);
  analogWrite(bluePinr, 255 - blueValuer);
}

void setColoru(int redValueu, int greenValueu, int blueValueu) {
  // Common anode RGB LED uses inverted logic, LOW is on, HIGH is off
  analogWrite(redPinu, 255 - redValueu);
  analogWrite(greenPinu, 255 - greenValueu);
  analogWrite(bluePinu, 255 - blueValueu);
}