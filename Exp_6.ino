void setup() {
  pinMode(A0, INPUT);         // Set pin A0 as input
  Serial.begin(9600);         // Begin serial communication at 9600 bps
  pinMode(13, OUTPUT);        // Set pin 13 as output
}

void loop() {
  float val = analogRead(A0); // Read the analog value from pin A0
  Serial.println(val);        // Print the value to the Serial Monitor

  if (val > 31) {             // Check if the value is greater than 31
    digitalWrite(13, HIGH);   // Turn on the LED on pin 13
  } else {
    digitalWrite(13, LOW);    // Turn off the LED on pin 13
  }

  delay(2000);                // Wait for 2 seconds before repeating the loop
}
