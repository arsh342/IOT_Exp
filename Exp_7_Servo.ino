void setup() {
  pinMode(6, OUTPUT); // Set pin 6 as an output
}

void loop() {
  digitalWrite(6, HIGH); // Turn on the LED (assuming pin 6 is connected to an LED)
  delay(2000);           // Wait for 2 seconds

  digitalWrite(6, LOW);  // Turn off the LED
  delay(2000);           // Wait for 2 seconds
}