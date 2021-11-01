#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN D4
#define LED_COUNT 8
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
IPAddress ip(192, 168, 0, 101);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress server(192, 168, 0, 100);
uint32_t white = strip.Color(255, 255, 255);
char ssid[] = "WeMos";
char pass[] = "12345678";
WiFiClient client;
void setup()
{
    Serial.begin(115200);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFI connected !");
    strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();  // Turn OFF all pixels ASAP
    strip.setBrightness(50);
}
void loop()
{
    String buffer;

    int axis[3], n;
    strip.clear();

    if (client.connect(server, 80))
    {
        Serial.println("connected to server !");
        client.println("hello");
        client.flush();
    }
    while (client.available())
    {
        buffer = client.readStringUntil('\n');
        Serial.println(buffer);
    }

    sscanf(buffer.c_str(), "%d %d %d", &axis[0], &axis[1], &axis[3]);
    for (int i = 0; i < axis[1]; i++)
    {
        strip.setPixelColor(i,white);
    }
    strip.show();
    client.stop();
}
