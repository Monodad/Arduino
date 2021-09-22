#include <Wire.h>
int device_contoll = 0xEB;
int device_address = 0x53; 
byte data_address[] = {0x32,0x33,0x34,0x35,0x36,0x37};
String txt[] = {"\nX : ","\nY : ","\nZ : "};
int set = '01101011';
int reg_read(byte address , byte register_address){
  Wire.beginTransmission(address);
  Wire.write(register_address);
  Wire.endTransmission(false);
  Wire.requestFrom(address,1);
   while(Wire.available())    // slave may send less than requested
  {   
    Serial.print(Wire.read(),DEC);

    // print the character
  }
  Serial.print(" ");
  Wire.endTransmission();
}
void setup() {
  // initialize serial communication at 9600 bits per second:
  
  Serial.begin(9600);
  Serial.print("Device ID : ");
  Wire.begin();
  Wire.setClock(100000);
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
  Serial.print("Set x31 value\n");
  Wire.beginTransmission(0x53);
  Wire.write(0x31);
  Wire.write(0x69);
  Wire.endTransmission();

Serial.print("Get x31 value : ");
   Wire.beginTransmission(0x53);
  Wire.write(0x31);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53,1);
   while(Wire.available())    // slave may send less than requested
  {   
    Serial.print(Wire.read(),BIN);         // print the character
  }
  Serial.print("\n");
  delay(1000);
  Wire.endTransmission();


  Wire.beginTransmission(0x53);
  Wire.write(0x2D);
  Wire.write(0x28);
  Wire.endTransmission();

}
int count = 0;
// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0 ; i<6;i++){
    reg_read(device_address , data_address[i]);
      Serial.print(txt[i/2]); 
    }

  delay(1000);
}
