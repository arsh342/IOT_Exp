// Define the digital pin for the IR sensor
const int irPin = 2;

// Variable to store the sensor state
int sensorState;

void setup() {
  // Set the irPin as an input
  pinMode(irPin, INPUT);
  
  // Begin the serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Read the state of the IR sensor
  sensorState = digitalRead(irPin);
  
  // Check if the sensor detects an object
  if (sensorState == LOW) {
    // Object detected
    Serial.println("Motion Detected");
  } else {
    // No object detected
    Serial.println("No Motion");
  }
  
  // Wait for 200 milliseconds before the next check
  delay(200);
}
