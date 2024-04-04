// Include necessary libraries
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <DHT_U.h>
#include "credendtials.h"
#include <ThingSpeak.h>

// Define network credentials and server details
char ssid[] = SSID;   
char pass[] = PASS;   
const char* server = SERVER;
unsigned long channeId = CHANNEL_ID;
const char* apiKey = WRITE_API_KEY;

// Create a WiFi client object
WiFiClient client;

// Define the pin where the DHT22 sensor is connected
#define DHTPIN D2 
DHT dht(DHTPIN, DHT22);

void setup(){
  // Initialize serial communication for debugging
  Serial.begin(9600); 
  // Initialize the DHT sensor
  dht.begin();
  // Initialize ThingSpeak library
  ThingSpeak.begin(client);

  // Attempt to connect to WiFi
  Serial.println("Connecting to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass); 
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop(){
  // Check if WiFi is connected
  if(WiFi.status() != WL_CONNECTED){
    return;
  }
  // Read humidity and temperature from the DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  // Check if readings are valid
  if (isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Set ThingSpeak fields with sensor readings
  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  
  // Print readings to serial monitor
  printToSerial(t, h);
  // Write fields to ThingSpeak
  int status = ThingSpeak.writeFields(channeId, apiKey);

  // Check if update was successful
  if(status == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(status));
  }
  // Delay to comply with ThingSpeak's minimum update interval
  Serial.println("Waiting 15 seconds...");
  delay(15000);
}

void printToSerial(float t, float h){
  // Print temperature and humidity readings to serial monitor
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C   Humidity: "));
  Serial.print(h);
  Serial.println(F("%"));
}
