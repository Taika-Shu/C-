#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <Adafruit_BMP085.h>

// WiFi Settings
const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";

// ThingSpeak Settings
unsigned long channelID = Your_Channel_ID;
const char* writeAPIKey = "Your_Write_API_Key";

// Sensor Settings
#define DHT_PIN D2
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_BMP085 bmp;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    while (1) {}
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  // Read DHT22 data
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read BMP180 data
  float pressure = bmp.readPressure() / 100.0; // Convert to hPa

  // Check if readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Set ThingSpeak fields
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, pressure);

  // Send data to ThingSpeak
  int statusCode = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (statusCode == 200) {
    Serial.println("Data pushed to ThingSpeak successfully!");
  } else {
    Serial.println("Error pushing data to ThingSpeak. HTTP error code: " + String(statusCode));
  }

  // Wait before next update (ThingSpeak requires at least 15 seconds between updates)
  delay(20000); // 20 seconds
}