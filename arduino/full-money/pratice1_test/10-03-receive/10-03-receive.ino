#include <afstandssensor.h>
#include <LiquidCrystal_PCF8574.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "LedControl.h"
LiquidCrystal_PCF8574 lcd(0x27);
LedControl lc = LedControl(D7, D8, D5, 1);
// AfstandsSensor(triggerPin, echoPin);
AfstandsSensor afstandssensor(D5, D4); // Starter afstandssensoren på ben 13 og 12.

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES 10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

//*****************WIFI****************

char ssid[] = "WeMos"; //  your network SSID (name)
char password[] = "12345678";
char server[] = "192.168.0.100";
int status = WL_IDLE_STATUS;

char OLED_buffer[128];
int show = -1;
WiFiClient client;
void setup()

{
  Serial.begin(115200); // Opsætter serial kommunikation tilbage til computeren
  int error;
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();

  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Result: ");
  Serial.print(error);

  if (error == 0)
  {
    Serial.println(": LCD found.");
    show = 0;
    lcd.begin(16, 2); // initialize the lcd
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.print("Hello LCD");
  }
  else
  {
    Serial.println(": LCD not found.");
  }

  Wire.beginTransmission(0x53);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();

  Wire.beginTransmission(0x53);
  Wire.write(0x31);
  Wire.write(0);
  Wire.endTransmission();
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  router();
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println();
  }
} // setup()

void loop()
{
  if (!client.connected()) {
    if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println();
    }
  }
  byte data[6];
  int i = 0;
  int16_t xyz[3];
  String test;
  Wire.beginTransmission(0x53);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53, 6);
  while (Wire.available())
  {
    data[i++] = Wire.read();
  }

  lcd.clear();
  while (client.available()) {
    OLED_buffer[i] = client.read();

    if(OLED_buffer[i]=='\r'){
      OLED_buffer[i] = ' ';
      break;
    }
    else{
      i = i + 1;
      
    }
    
  }

  Serial.println(OLED_buffer[3] + OLED_buffer[4]);
  draw_xyz_led();
  client.flush();
}

void draw_mat(int16_t *xyz)
{
  lc.clearDisplay(0);
  lc.setRow(0, 4 + xyz[1] / 20, 1 << 3 + xyz[0] / 20);
}

void draw_xyz_led()
{


  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.cp437(true);
  display.print(OLED_buffer);
  display.display();

}
void router(void)
{
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
