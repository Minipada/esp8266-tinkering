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
}
