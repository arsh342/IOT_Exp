#include "DHT.h"

// Define the pin where the data pin of the DHT22 is connected
#define DHTPIN 2 

// Define the type of DHT sensor
#define DHTTYPE DHT22 

// Create a DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);
  
  // Read humidity and temperature values from the DHT22 sensor
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature(); // in Celsius
  float temperatureF = dht.readTemperature(true); // in Fahrenheit
  
  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C ");
  Serial.print(temperatureF);
  Serial.println(" °F");
}
