#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const char* ssid = "WeMos";
const char* password = "12345678";
ESP8266WebServer server(80);


void setup() {
  String index = "<h1>Simple NodeMCU Web Server</h1>";
  Serial.begin(115200);
  
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.println(myIP);
  server.send(200, "text/html", index);
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  // put your main code here, to run repeatedly:
 server.handleClient();
}
