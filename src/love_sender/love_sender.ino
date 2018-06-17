#include "wifi.h"
#include "capacitive_sensor.h"
#include "leds.h"
#include "server.h"

//const char* ssid = "Danger Zone";
//const char* password = "435811375";
const char* ssid = "Giorgi";
const char* password = "595302010";
CapacitiveSensor cs_4_5 = CapacitiveSensor(4, 5);
WiFiClient client;
String host = "51.15.60.151";
const int http_port = 80;
int non_active_cs = 0;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  connect_wifi(ssid, password);
  Serial.println("Connected to wifi...");

  init_tcp_connection(client, host, http_port);
  Serial.println("Connected to server...");

  setup_cs(cs_4_5);
  Serial.println("Capacitive sensor setup...");

  setup_ws2812();
  Serial.println("LEDs setup...");

  non_active_cs = sensor_calibration(cs_4_5);
  Serial.println("Capacitive sensor calibrated");
}

void loop() {
  bool done = false;
  Serial.print("Sensor: ");
  Serial.println(non_active_cs);
  
  // If button pressed, dim your light and send the request
  if (get_cs_status(cs_4_5, non_active_cs)) {
    done = false;
    turn_leds_on();
    init_tcp_connection(client, host, http_port);
    Serial.println("Sensor activated");
    request_uri(client, (String) "index.php", host, (String) "nasim");
    Serial.println("Request URI...");
    delay(500);
    // Read all the lines of the reply from server and dim light when it is received
    while (client.available() && done == false) {
      Serial.println("client available");
      String line = client.readStringUntil('\r');
      if (line == "\nFileCreatedNasim") {
        Serial.println("File was created...");
        done = true;
      }
    }
  }
  else {
    if (init_tcp_connection(client, host, http_port)){
      done = false;
      Serial.println("Check server");
      request_uri(client, (String) "index.php", host, (String) "isdimmednasim");
      delay(500);
  
      // Read all the lines of the reply from server and dim light when it is received
      while(client.available() && done == false){
        String line = client.readStringUntil('\r');
        if (line == "\nHitTheLightsNasim"){
          Serial.println("Hit the lights...");
          turn_leds_on();
          done = true;
        }
      }
    }
  }
}
