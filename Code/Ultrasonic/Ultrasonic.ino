// Define the Trig and Echo pin:
#define TRIG_PIN 23 // A0
#define ECHO_PIN 22 // A1


// Define the speed of sound in cm/us:
#define SOUND_SPEED 0.034

void setup() {
  // Begin the serial communication
  Serial.begin(9600);
  
  // Define the Trig pin as an OUTPUT and Echo pin as an INPUT:
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Clear the TRIG_PIN by setting it to LOW:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  
  // Trigger the sensor by setting the TRIG_PIN high for 10 microseconds:
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the time it takes for the echo to return to the sensor:
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance:
  float distance = (duration * SOUND_SPEED) / 2;
  
  // Print the distance on the Serial Monitor:
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Delay for a bit to avoid overlapping readings:
  delay(10);
}
