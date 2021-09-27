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
    for (byte p = 0; p < 3; p++) {
      pinMode(scan_p[p], OUTPUT);
    }
    for (byte p = 0; p < 8; p++) {
      pinMode(dot_row_p[p], OUTPUT);
    }
    for (byte p = 0; p < 4; p++) {
      pinMode(kb_row_p[p], INPUT);
    }
}

byte dot_out[8] = {0}, offset = 0;
byte row_cnt = 0;

void loop(){
    scan();

    byte key = read_key();
    switch(key)
    {
        case 1:
            for (int i = 0; i < 8; i++) {
                dot_out[i] = (byte)(big_and_small[i] >> 8);
            }
            break;
        case 2:
            for (int i = 0; i < 8; i++) {
                dot_out[i] = (byte)(big_and_small[i] & 0xff);
            }
            break;
        case 3:
            shift(false);
            break;
        case 4:
            shift(true);
            break;
    }   
    display();
}


void scan() {
    if (row_cnt == 7) {
      row_cnt = 0;
      return 1;
    } else {
      row_cnt++;
    }
    for (byte i = 0; i < 3; i++) {
      digitalWrite(scan_p[i], row_cnt & (1 << i));
         delay(100);
    }
 
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
