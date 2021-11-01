#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
// #include "head.h"
#define LED D4
#define TACT D3
#define relay D0
#define VR A0
IPAddress ip(192, 168, 0, 5);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 0, 1);
char *SSID = "WeMos";
char *PASS = "12345678";
ESP8266WebServer server(80);
Adafruit_SSD1306 dis(128, 64);
String security = "Safe", LED_status = "ON", FAN = "ON";
int temp = 0;
const char *head = (R"===(
<html>
    <head>
        <title>48-1</title>
        <meta http-equiv="refresh" content="1" />
    </head>
    <body>
        <p>LIGHT :  <a href="/ledon">    ON</a>     <a href="/ledoff">OFF</a></p>
        <p>Security : %s</p>
        <p>Temp : %d</p>
        <p></p>
        <p>LED : %s</p>
        <p>FAN : %s</p>

    </body> 
</html>


)===");
bool LED_light = 0;
void LED_off();
void LED_on();
void setup()
{
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    pinMode(relay, OUTPUT);
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    while (!dis.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
        // Don't proceed, loop forever
    }
    Serial.println(F("SSD1306 allocation SUCCEED"));
    dis.clearDisplay();
    dis.setTextColor(1);

    dis.display();
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(SSID, PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    dis.println(WiFi.localIP());
    dis.display();
    server.on("/", LED_on);
    server.on("/ledoff", LED_off);
    server.on("/ledon", LED_on);
    Serial.println("Connected");
    // server.on("/Led", status);
    server.begin();
}
u32 read = 0;

void loop()
{
    if (millis() - read > 500)
    {
        temp = map(analogRead(VR), 0, 1023, 25, 35);
        if (digitalRead(TACT))
        {
            security = "Safe";
        }
        else
            security = "Warning";
        read = millis();
    }

    if (temp >= 30)
    {
        FAN = "ON";
        digitalWrite(relay, 0);
    }
    else if (temp <= 26)
    {
        FAN = "OFF";
        digitalWrite(relay, 1);
    }

    digitalWrite(LED, LED_light);
    server.handleClient();
}
void LED_off()
{
    char html[500];
    LED_light = 0;
    sprintf(html, head, security, temp, "OFF", FAN);
    server.send(200, "text/html", html);
}
void LED_on()
{
    char html[500];
    LED_light = 1;
    sprintf(html, head, security, temp, "ON", FAN);
    server.send(200, "text/html", html);
}
