#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

#define DHTPIN 2 
#define DHTTYPE DHT11       

DHT dht(DHTPIN, DHTTYPE);

// WiFi settings
const char* ssid = "Wifi";
const char* password = "Password";

// ThingSpeak settings
const unsigned long channelID = 2687409;
const char* apiKey = "0O60ADN0CL7945";

WiFiClient client;

void setup() {
    Serial.begin(115200);       // Start serial communication
    dht.begin();                // Start DHT sensor
    WiFi.begin(ssid, password); // Start WiFi connection

    Serial.println("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("Connected to WiFi");
    ThingSpeak.begin(client);   // Start ThingSpeak connection
}

void loop() {
    float temperature = dht.readTemperature(); // Read temperature
    float humidity = dht.readHumidity();       // Read humidity

    // Check if any reads failed
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Error reading sensor data");
    } else {
        // Send data to ThingSpeak
        ThingSpeak.setField(1, temperature);
        ThingSpeak.setField(2, humidity);
        ThingSpeak.writeFields(channelID, apiKey);

        // Print data to serial monitor
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C, Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }

    delay(20000); // Wait 20 seconds before next reading
}
