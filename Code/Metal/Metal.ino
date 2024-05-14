const int metalDetectorPin = 26; // The pin connected to the metal detector's buzzer output

void setup() {
  pinMode(metalDetectorPin, INPUT); // Set the metal detector pin as input
  Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {
  int detectorState = digitalRead(metalDetectorPin); // Read the metal detector output

  if (detectorState == HIGH) {
    // Metal is detected
    Serial.println("Metal detected!");
  } else {
    // No metal is detected
    Serial.println("No metal detected");
  }

  // You may want to add a small delay to avoid spamming the serial monitor
  delay(1);
}
