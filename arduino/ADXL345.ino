#include <Wire.h>
int device_contoll = 0xEB;
int device_address = 0x53; 
byte data_address[] = {0x32,0x33,0x34,0x35,0x36,0x37};
int reg_read(byte address , byte register_address){
  Wire.beginTransmission(address);
  Wire.write(register_address);
  Wire.endTransmission(false);
  Wire.requestFrom(address,1);
   while(Wire.available())    // slave may send less than requested
  {   
    Serial.print(Wire.read(),BIN);
    Serial.print("\n"); 
    // print the character
  }
  Wire.endTransmission();
}
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000);
  Wire.beginTransmission(0x53);
  Wire.write(0x00);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53,1);
   while(Wire.available())    // slave may send less than requested
  {   
    Serial.print(Wire.read(),BIN);         // print the character
  }
  Serial.print("\n"); 
  delay(1000);
  Wire.endTransmission();
}
int count = 0;
// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0 ; i<8;i++){
    reg_read(device_address , data_address[i]);
  }
  Serial.print("next\n");
}
