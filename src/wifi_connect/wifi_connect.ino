#include "ESP8266WiFi.h"

const char* ssid = "SSID";
const char* password = "PASSWORD";

void setup(void)
{ 
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println(WiFi.localIP());

}
void loop() {
}

