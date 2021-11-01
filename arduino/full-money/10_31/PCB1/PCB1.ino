#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 dis(128, 64);
IPAddress ip(192, 168, 0, 10);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

// IPAddress subnet()
WiFiServer server(80);
char *ssid = "WeMos";
char *pass = "12345678";
void setup()
{
  Serial.begin(115200);
  Wire.begin();
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);
  }
  Serial.println("connected");
  Serial.println(WiFi.localIP());
  Wire.beginTransmission(0x53);
  Wire.write(0x2D);
  Wire.write(0x08);
  Wire.endTransmission();
  Wire.beginTransmission(0x53);

  Wire.write(0x31);
  Wire.write(0x00);
  Wire.endTransmission();
  dis.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  server.begin();
}
u32 laptime[4] = {0};
u32 lap(int time) {
  return micros() - laptime[time];
}
int16_t read[2][128];
int count = 0;
void loop()
{
  int16_t *axis;
  WiFiClient client = server.available();

  if (lap(1) >= 10000)
  {
    axis = adxl();
    laptime[1] = micros();

    read[0][127] = axis[0];
    read[1][127] = axis[1];
    for (int g = 0; g < 2; g++)
    {
      for (int i = 0; i < 127; i++)
      {
        read[g][i] = read[g][i + 1];
      }
    }
  }
  if (client && axis[0]>128)
  {
    count ++;
    if (client.connected())
    {
      Serial.println("connected to client");

      if (client.available())
      {
        while (client.available())
        {
          Serial.println(client.readStringUntil('\n'));
        }
          client.println(axis[0]);
          client.flush();
          client.stop();
      }
    }
  }
  if (lap(2) >= 2'000'00)
  {
    laptime[2] = micros();
    dis.clearDisplay();
    for (int i = 0; i < 128; i++)
    {
      dis.drawPixel(i, map(read[0][i], -256, 256, 32, 0), WHITE);
      dis.drawPixel(i, map(read[1][i], -256, 256, 64, 32), WHITE);


    }

    draw();
    dis.display();
  }
}
int16_t *adxl()
{
  int i = 0;

  static char axis_buffer[7] = {0};

  static int16_t axis[3];
  Wire.beginTransmission(0x53);
  Wire.write(0x32);
  Wire.requestFrom(0x53, 6);
  while (Wire.available())
  {
    axis_buffer[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
  axis[0] = axis_buffer[1] << 8 | axis_buffer[0];

  axis[1] = axis_buffer[3] << 8 | axis_buffer[2];

  axis[2] = axis_buffer[5] << 8 | axis_buffer[4];

  return axis;
}
void draw()
{
  dis.drawRect(0, 4, 127, 60, 1);
  dis.writeFastVLine(64, 4, 60, 1);
  dis.writeFastHLine(0, 32, 128, 1);
}
