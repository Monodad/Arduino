#include <Wire.h>
#include <ESP8266WiFi.h>
#include "LedControl.h"
LedControl lc(D7, D5, D6);
IPAddress ip(192, 168, 0, 100);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
char ssid[] = "WeMos";
char pass[] = "12345678";
WiFiServer server(80);
int16_t axis[3];
void setup()
{
    Serial.begin(115200);
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, pass);
    Serial.print("Connect to router");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFI connected !");
    server.begin();
    lc.shutdown(0, false);
    /*adxl*/
    Wire.begin();
    Wire.beginTransmission(0x53);
    Wire.write(0x2D);
    Wire.write(0x08);
    Wire.endTransmission();
    Wire.beginTransmission(0x53);
    Wire.write(0x31);
    Wire.write(0x00);
    Wire.endTransmission();
    lc.clearDisplay(0);
}

void loop()
{
    int16_t row;
    adxl();
    lc.clearDisplay(0);
    // Serial.println(axis[0]);
    // Serial.println(axis[1]);
    // Serial.println(axis[2]);

    for (int i = 0; i < 8; i++)
    {
        for (int g = 0; g < axis[1]; g++)
            lc.setLed(0, i, g, 1);
    }
    if(axis[2]==0)lc.clearDisplay(0);
    char buffer[10];
    sprintf(buffer, "%d %d %d", axis[0], axis[1], axis[2]);
    WiFiClient client = server.available();
    if (client)
    {
        if (client.connected())
        {
            Serial.println("connected to client");

            if (client.available())
            {
                while (client.available())
                {
                   Serial.println(client.readStringUntil('\n'));
                }
                client.println(buffer);
            }
        }
    }
 
}
void adxl()
{
    int i = 0;
    static byte adxl_buffer[6];
    Wire.beginTransmission(0x53);
    Wire.write(0x32);
    Wire.requestFrom(0x53, 6);
    while (Wire.available())
    {
        adxl_buffer[i] = Wire.read();
        i++;
    }
    Wire.endTransmission();
    axis[0] = (int16_t)adxl_buffer[1] << 8 | adxl_buffer[0];
    axis[1] = (int16_t)adxl_buffer[3] << 8 | adxl_buffer[2];
    axis[2] = (int16_t)adxl_buffer[5] << 8 | adxl_buffer[4];

    axis[0] = map(axis[0], -256, 256, 0, 8);
    axis[1] = map(axis[1], -256, 256, 0, 8);
    axis[2] = map(axis[2], -256, 256, 0, 8);
}