// Define the analog pin connected to AO
const int analogPin = A0;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the sensor
  int analogValue = analogRead(analogPin);
  
  // Print the analog value to the Serial Monitor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  
  // Wait for 1 second before reading again
  delay(1000);
}
