#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* device_owner = "david";
const char* ssid = "Khaleesi4life";
const char* password = "not4youbaby";

void setup () {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting...");
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

// Use WiFiClient class to create TCP connections
bool init_tcp_connection(WiFiClient& client, String host, const int http_port) {
  if (!client.connect(host, http_port)) {
    Serial.println("connection failed");
    return false;
  }
  
  return true;
}

// We now create a URI for the request
void request_uri(WiFiClient& client, String param, String host, String data){
  String url = "GET /" + param + "?" + data + " HTTP/1.1";
  
  client.println(url);
  client.println("Host: " + host);
  client.println("Connection: close");
  client.println();
  
  delay(500);
}

bool button_pressed(){
  return true;  
}

void loop() {
  WiFiClient client;
  String host = "192.168.1.34";
  const int http_port = 80;

  init_tcp_connection(client, "127.0.0.1", 80);

}
