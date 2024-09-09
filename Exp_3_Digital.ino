// Define the digital pin connected to DO
const int digitalPin = 8;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  
  // Set the digital pin as input
  pinMode(digitalPin, INPUT);
}

void loop() {
  // Read the digital value from the sensor
  int digitalValue = digitalRead(digitalPin);
  
  // Print the digital value to the Serial Monitor
  Serial.print("Digital Value: ");
  Serial.println(digitalValue);
  
  // Wait for 1 second before reading again
  delay(1000);
}
