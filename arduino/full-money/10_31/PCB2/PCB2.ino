#include <ESP8266WiFi.h>
WiFiClient client;
IPAddress ip(192, 168, 0, 11);
IPAddress server(192, 168, 0, 10);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
char *ssid = "WeMos", *pass = "12345678";

void setup()
{
  pinMode(D6, OUTPUT);
  pinMode(D0, OUTPUT);

  Serial.begin(115200);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);
  }
  Serial.println("connected");
  Serial.println(WiFi.localIP());

}
int count = 0;
void loop()
{
  String buffer;
  int x = 0, rece = 0;
  if (client.connect(server, 80))
  {
    client.println();
    client.flush();
  }
  while (client.available())
  {
    buffer = client.readStringUntil('\n');
    sscanf(buffer.c_str(), "%d", &x);
    rece = 1;
  }
  if (x > 200 && rece == 1) {
    if (count == 4) {
      count = 0;
    } else {
      Serial.println(x);
      Serial.println(count);
      digitalWrite(D6, count / 2);
      digitalWrite(D0, count % 2);
      count++;
      delay(100);
    }
    rece = 0;
  }
 
}
