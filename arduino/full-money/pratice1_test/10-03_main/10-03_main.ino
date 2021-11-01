#include <Wire.h>
#include <WiFiNINA.h>
#include <SPI.h>
int status = WL_IDLE_STATUS;
char ssid[] = "WeMos"; //  your network SSID (name)
char password[] = "12345678";
char data_buffer[128];
const int port = 80;
WiFiServer server(80);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  router();
  adxl_setup();
  
}

void loop() {

  adxl_read();
 

   server.write(data_buffer);
  
   delay(100);
}

void adxl_setup(void){
  Wire.begin();
  Wire.beginTransmission(0x53);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();

  Wire.beginTransmission(0x53);
  Wire.write(0x31);
  Wire.write(0);
  Wire.endTransmission();
}
void adxl_read(void){
  byte data[6],i=0;;
  int16_t xyz[3];
  Wire.beginTransmission(0x53);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53, 6);
  while (Wire.available()) {
    data[i++] = Wire.read() ;
  }
  xyz[0] = (int16_t)data[1] << 8 | data[0];
  xyz[1] = (int16_t)data[3] << 8 | data[2];
  xyz[2] = (int16_t)data[5] << 8 | data[4];
  xyz[0] = map(xyz[0], -256, 256, -90, 90);
  xyz[1] = map(xyz[1], -256, 256, -90, 90);
  xyz[2] = map(xyz[2], -256, 256, -90, 90);
  sprintf(data_buffer, "X :%2d%c\nY :%2d%c\nZ :%2d%c\r", xyz[0], 0xF8, xyz[1], 0xF8, xyz[2], 0xF8);
}
void router(void)
{
  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    status = WiFi.begin(ssid, password);
    delay(500);
  }

  Serial.println("Connected to wifi");
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());
  server.begin();
}
