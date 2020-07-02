#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ThingsBoard.h>
#include <Arduino_JSON.h>
#include <ArduinoJson.h>

#define WIFI_AP "YOUR_WIFI_AP"
#define WIFI_PASSWORD "YOUR_WIFI_PW"
#define TOKEN "YOUR_DEVICE_ACCESS_TOKEN"


char thingsboardServer[] = "cloud.thingsboard.io";
WiFiClient wifiClient;
ThingsBoard tb(wifiClient);
int status = WL_IDLE_STATUS;
int pin = 2; // WiFi module GPIO connected to the LED

void setup() {
  Serial.begin(115200);
  pinMode(pin, OUTPUT);  
  delay(10);
  InitWiFi();
}

void loop() {
  if (!tb.connected()) {
    reconnect();
  }

  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://cloud.thingsboard.io/api/plugins/telemetry/DEVICE/YOUR_ENTITY_ID/values/timeseries?keys=shake,avgDiscobolus,avgVenus");
    http.addHeader("Content-Type", "application/json");
    http.addHeader("X-Authorization","Bearer YOUR_THINGSBOARD_ACCESS_TOKEN");
  
    int httpCode = http.GET(); // Send the request
  
    if (httpCode > 0) { // Check the returning code
      DynamicJsonDocument doc(2048);

      DeserializationError error = deserializeJson(doc, http.getString());
      // Test if parsing succeeds.
      if (error) {
        Serial.print(("deserializeJson() failed: "));
        Serial.println(error.c_str());
        return;
      }

      String artwork = (doc["shake"][0]["value"]);
      double avgVenus = (doc["avgVenus"][0]["value"]);
      double avgDiscobolus = (doc["avgDiscobolus"][0]["value"]);
      double maxAvg = max(avgVenus,avgDiscobolus);
      String avgArtwork = "avg"+artwork;
      double currentAvg = doc[avgArtwork][0]["value"];

      // Check if the current artwork is the most appreciated
      if (currentAvg == maxAvg) {
        digitalWrite(pin, LOW); // Set the LED on
      } else {
        digitalWrite(pin, HIGH); // Set the LED off 
      }
      
    }
    http.end(); // Close connection
  }

  delay(20000); 
  tb.loop();
}

// Connect to WiFi
void InitWiFi() {
  Serial.println("Connecting to AP ...");
  // Attempt to connect to WiFi network

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");
}


void reconnect() {
  // Loop until we're reconnected
  while (!tb.connected()) {
    status = WiFi.status();
    if (status != WL_CONNECTED) {
      WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("Connected to AP");
    }
    Serial.print("Connecting to ThingsBoard node ...");
    if (tb.connect(thingsboardServer, TOKEN)) {
      Serial.println("[DONE]");
    } else {
      Serial.print("[FAILED]");
      Serial.println(" : retrying in 5 seconds]");
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}
