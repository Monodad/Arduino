#include <Wire.h>
const int device_address = 0x53;

void setup() {
  // initialize serial communication at 9600 bits per second:

  Serial.begin(9600);
  Serial.print("Device ID : ");
  Wire.begin();
  Wire.setClock(100000);
  Wire.beginTransmission(0x53);
  Wire.write(0x00);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53, 1);
  while (Wire.available())   // slave may send less than requested
  {
    Serial.print(Wire.read(), BIN);        // print the character
  }
  Serial.print("\n");
  delay(1000);
  Wire.endTransmission();
  Serial.print("Set x31 value\n");
  Wire.beginTransmission(0x53);
  Wire.write(0x31);
  Wire.write(0b01101000);
  Wire.endTransmission();

  Serial.print("Get x31 value : ");
  Wire.beginTransmission(0x53);
  Wire.write(0x31);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53, 1);
  while (Wire.available())   // slave may send less than requested
  {
    Serial.print(Wire.read(), BIN);        // print the character
  }
  Serial.print("\n");
  delay(1000);
  Wire.endTransmission();


  Wire.beginTransmission(0x53);
  Wire.write(0x2D);
  Wire.write(0x28);
  Wire.endTransmission();
}

void loop() {
   int *xyz = reg_read(device_address);
  
  for (int i = 0; i < 3; i++) {
    Serial.println(xyz[i]);
  }
  
  delay(1000);
}



 int *reg_read(byte address) {
  Wire.beginTransmission(address);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(address, 6);

  byte data[6];
  byte i = 0;
  while (Wire.available() && i++ < 6){
    data[i] = Wire.read();
    Serial.print("TEST: ");
    Serial.println(data[i]);
  }
  Wire.endTransmission();

  static  int xyz[3];
  for (int i = 0; i < 3; i++) {
    xyz[i] = data[i*2 + 1];
    xyz[i] <<= 8;
    xyz[i] |= data[i*2];
  }

  return xyz;
}
