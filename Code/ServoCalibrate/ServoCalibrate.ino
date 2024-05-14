#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;

void setup() {
  
  s1.attach(2);
  s2.attach(3);
  s3.attach(6);
  s4.attach(4); 

  // Start the serial communication
  Serial.begin(9600);
  Serial.println("Servo Test Code!");
  Serial.println("Send '1,angle' to move servo s1, '2,angle' for servo s2, etc.");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    String inputString = Serial.readString(); // Read the incoming data as string
    int commaIndex = inputString.indexOf(','); // Find the position of the comma
    if (commaIndex != -1) {
      int servoNumber = inputString.substring(0, commaIndex).toInt(); // Get the servo number
      int angle = inputString.substring(commaIndex + 1).toInt(); // Get the angle
      moveServoToAngle(servoNumber, angle); // Move the appropriate servo
    }
  }
}

void moveServoToAngle(int servoNumber, int angle) {
  // Constrain the angle to avoid potential damage to the servo
  angle = constrain(angle, 0, 180);
  
  // Move the specified servo to the given angle
  switch (servoNumber) {
    case 1:
      s1.write(angle);
      break;
    case 2:
      s2.write(angle);
      break;
    case 3:
      s3.write(angle);
      break;
    case 4:
      s4.write(angle);
      break;
    default:
      Serial.println("Invalid servo number");
  }
}
