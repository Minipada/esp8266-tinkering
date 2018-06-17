#include "ESP8266WiFi.h"

void connect_wifi(const char* ssid, const char* password)
{
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting...\n");
    delay(1000);
  }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}