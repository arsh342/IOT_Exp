// Define pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Variables to store the duration of the pulse and the distance
long duration;
int distance;

void setup() {
  // Set the trigPin as an output and the echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Begin serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond HIGH pulse to trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the pulse on echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters (speed of sound = 0.034 cm/µs)
  distance = duration * 0.034 / 2;
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait before the next measurement
  delay(60);
}
