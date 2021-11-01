const byte scan_p[] = {12, 3, 2};                    // LSB first
const byte dot_row_p[] = {4, 5, 6, 7, 8, 9, 10, 11}; // Row 0 first
const byte kb_row_p[] = {A0, A1, A2, A3};            // Row 0 first

const uint16_t big_and_small[] = {
    0b0001000000001000,
    0b0001000000001000,
    0b0111111000101000,
    0b0001000001001010,
    0b0010100010001001,
    0b0100010000011000,
    0b1000001000001000,
    0b0000000000000000,
};

void setup()
{
  Serial.begin(115200);
  for (byte p = 0; p < 3; p++)
  {
    pinMode(scan_p[p], OUTPUT);
  }
  for (byte p = 0; p < 8; p++)
  {
    pinMode(dot_row_p[p], OUTPUT);
  }
  for (byte p = 0; p < 4; p++)
  {
    pinMode(kb_row_p[p], INPUT);
  }
  for (byte p = 0; p < 8; p++)
  {
    digitalWrite(dot_row_p[p], LOW);
  }
}

int time = millis();
byte dot_out[8] = {0}, offset = 0;
byte row_cnt = 1;
int timeCount = 0;
int shift = 0;
int timer = 0;
int time_set = 0, time_passed = 0;

void loop()
{
  timer = timer_a();
  Serial.println(timer);
  display_dev();
}

int timer_a()
{
  if (time_set == 0)
  {
    time_set = millis();
  }
  time_passed = millis() - time_set;
  if (time_passed > 500)
  {
    time_set = 0;
    shift++;
    return 0;
  }
  else
  {
    return time_passed;
  }
}

void display_dev()
{
  for (int i = shift; i < 8; i++)
  {
    for (int g = 0; g < 8; g++)
    {
      digitalWrite(dot_row_p[g], !((big_and_small[g] >> i) % 2));
    }
    // delay(2);
    scan();

    // if (timeCount == 10)
    // {
    //   scan();
    //   timeCount = 0;
    // }
  }
  // if (timer >= 450)
  // {
  //   shift += 1;
  // }
  // time_set = 0;
  // timer = 0;
  if (shift == 7)
  {
    shift = 0;
  }
}

void scan()
{
  if (row_cnt == 7 - shift)
  {
    row_cnt = 0;
  }
  else
  {
    row_cnt++;
  }

  // timer = timer + 1;
  digitalWrite(scan_p[2], !((row_cnt & 0b100) >> 2));
  digitalWrite(scan_p[1], !((row_cnt & 0b010) >> 1));
  digitalWrite(scan_p[0], !(row_cnt & 0b001));
}

void all_dark()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(dot_row_p[i], 1);
  }
}

// If nothing is pressed, returns 0
byte read_key()
{
  if (row_cnt < 4)
  {
    for (int i = 0; i < 4; i++)
    {
      if (digitalRead(kb_row_p[i]) == 0)
      {
        return row_cnt + i * 4;
      }
      delay(10);
    }
  }
  else
  {
    return 0;
  }
}

void shifts(bool right)
{
  if (right)
  {
    if (offset == 16)
    {
      offset = 0;
    }
    else
    {
      offset++;
    }
  }
  else
  {
    if (offset == 0)
    {
      offset = 16;
    }
    else
    {
      offset--;
    }
  }
}

void display()
{
  for (byte c = 0; c < 8; c++)
  {
    // c: column
    digitalWrite(dot_row_p[c], dot_out[row_cnt] & (1 << c));
  }
}
