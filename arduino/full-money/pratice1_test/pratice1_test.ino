const byte scan_p[] = {12,3,2}; // LSB first
const byte dot_row_p[] = {4,5,6,7,8,9,10,11}; // Row 0 first
const byte kb_row_p[] = {A0,A1,A2,A3}; // Row 0 first

const int big_and_small[] = 
{
    0b0001000000001000,
    0b0001000000001000,
    0b0111111000101000,
    0b0001000001001010,
    0b0010100010001001,
    0b0100010000011000,
    0b1000001000001000,
    0b0000000000000000
};


void setup(){
   Serial.begin(9600);
    for (byte p = 0; p < 3; p++) {
      pinMode(scan_p[p], OUTPUT);
    }
    for (byte p = 0; p < 8; p++) {
      pinMode(dot_row_p[p], OUTPUT);
    }
     for (byte p = 0; p < 8; p++) {
      digitalWrite(dot_row_p[p], 0);
    }
    for (byte p = 0; p < 4; p++) {
      pinMode(kb_row_p[p], INPUT);
    }
}

byte dot_out[8] = {0}, offset = 0;
byte row_cnt = 0;
int timeCount = 0;
void loop(){
    timeCount +=  1;
    display_dev();
}

void display_dev(){
   for(int i = 0;i<8;i++){
    for(int g = 0 ;g < 8; g++){
       digitalWrite(dot_row_p[g] ,!((big_and_small[g] >> i) % 2));
    }
        delay(5);
        scan();
   //   if(timeCount == 10){
   //       scan();
   //       timeCount = 0;
   //}
   }
}
void scan() {
    if (row_cnt == 7) {
      row_cnt = 0;
    } else {
      row_cnt++;
    }
    digitalWrite(scan_p[2], !((row_cnt & 0b100)>> 2));
    digitalWrite(scan_p[1], !((row_cnt & 0b010)>> 1));
    digitalWrite(scan_p[0], !(row_cnt & 0b001));
    

}

// If nothing is pressed, returns 0
byte read_key() {
    if(row_cnt < 4){
        for(int i = 0;i<4;i++){
            if(digitalRead(kb_row_p[i]) == 0)
                return row_cnt + i * 4;
            delay(10);                                                                                                               
        }
    }
    else{
        return 0;
    }
}

void shift(bool right) {
  if (right) {
    if (offset == 16) {
        offset = 0;
    } else {
        offset++;
    }
    
  } else {
    if (offset == 0) {
        offset = 16;
    } else {
        offset--;
    }
  }
}

void display() {
  for (byte c = 0; c < 8; c++) { // c: column
    digitalWrite(dot_row_p[c], dot_out[row_cnt] & (1 << c));
  }
}
