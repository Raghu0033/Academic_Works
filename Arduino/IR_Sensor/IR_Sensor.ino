int irPin = 2; // Pin connected to the IR sensor's output

void setup() {
  pinMode(irPin, INPUT); // Set the IR pin as an input
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(irPin);
  Serial.println(sensorValue);
  if (sensorValue == LOW) {
    Serial.println("Object detected");
  } else {
    Serial.println("No object detected");
  }

  delay(1000); // Adjust delay as needed
}