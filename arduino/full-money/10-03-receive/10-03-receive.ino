#include <afstandssensor.h>
#include <LiquidCrystal_PCF8574.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <WiFi.h>
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
char pass[] = "12345678";
int status = WL_IDLE_STATUS;
WiFiClient client;

int show = -1;
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

} // setup()

void loop()
{
  byte data[6], i = 0;
  int16_t xyz[3];
  Wire.beginTransmission(0x53);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53, 6);
  while (Wire.available())
  {
    data[i++] = Wire.read();
  }

  // Måler afstanden for hver 500ms
  lcd.clear();
  //  lcd.print(afstandssensor.afstandCM());
  //  Serial.println(afstandssensor.afstandCM());
  xyz[0] = (int16_t)data[1] << 8 | data[0];
  xyz[1] = (int16_t)data[3] << 8 | data[2];
  xyz[2] = (int16_t)data[5] << 8 | data[4];
  xyz[0] = map(xyz[0], -256, 256, -90, 90);
  xyz[1] = map(xyz[1], -256, 256, -90, 90);
  xyz[2] = map(xyz[2], -256, 256, -90, 90);
  //  Serial.println(xyz[0],DEC);
  //  Serial.println(xyz[1],DEC);
  //  Serial.println(xyz[2],DEC);
  draw_xyz_led(xyz);
  draw_mat(xyz);
  delay(100);
}

void draw_mat(int16_t *xyz)
{
  lc.clearDisplay(0);
  lc.setRow(0, 4 + xyz[1] / 20, 1 << 3 + xyz[0] / 20);
}

void draw_xyz_led(int16_t *xyz)
{
  char OLED_buffer[32];

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  sprintf(OLED_buffer, "X :%2d%c\nY :%2d%c\nZ :%2d%c", xyz[0], 0xF8, xyz[1], 0xF8, xyz[2], 0xF8);
  display.setCursor(0, 0);
  display.cp437(true);
  display.println(OLED_buffer);
  display.display();
}
void router(void)
{
  while (status != WL_CONNECTED)
  {

    Serial.print("Attempting to connect to SSID: ");

    Serial.println(ssid);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:

    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:

    delay(10000);
  }
  Serial.println("Connected to wifi");
  Serial.println(WiFi.localIP());

}
