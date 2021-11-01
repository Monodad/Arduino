#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
#define R0 D3
#define R1 D4
#define C3 D8
#define C2 D7
#define C1 D6
#define C0 D5
int row[] = {R0, R1};
int col[] = {C0, C1, C2, C3};
int64_t num = 0;
int16_t pre, pre_v;
String buffer = "", temp = "", pre_temp = "";
bool pressed, opr = '0';
volatile int key, i;

ICACHE_RAM_ATTR void get_key_C0()
{
    key = i * 4 + 1;
}
ICACHE_RAM_ATTR void get_key_C1()
{
    key = i * 4 + 2;
}
ICACHE_RAM_ATTR void get_key_C2()
{
    key = i * 4 + 3;
}
ICACHE_RAM_ATTR void get_key_C3()
{
    key = i * 4 + 4;
}

void setup()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    Serial.begin(115200);
    pinMode(R0, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(C0, INPUT);
    pinMode(C1, INPUT);
    pinMode(C3, INPUT);
    pinMode(C2, INPUT);
    attachInterrupt(digitalPinToInterrupt(C0), get_key_C0, FALLING);
    attachInterrupt(digitalPinToInterrupt(C1), get_key_C1, FALLING);
    attachInterrupt(digitalPinToInterrupt(C2), get_key_C2, FALLING);
    attachInterrupt(digitalPinToInterrupt(C3), get_key_C3, FALLING);
    display.display();
    delay(500);
    for (int i = 0; i < 2; i++)
    {
        digitalWrite(row[i], HIGH);
    }
}

void loop()
{
    key_broad();

    if (key != 0)
    {
        switch (key)
        {
        case 10:
            buffer = buffer + "+";
            opr = '1';
            key = 0;
            break;
        case 11:
            buffer = buffer + "-";
            key = 0;
            opr = '1';
            break;
        case 12:
            buffer = buffer + "*";
            opr = '1';
            key = 0;
            break;
        case 13:
            OLED_setup(String(cal(buffer)));
            delay(1000);
            key = 0;
            buffer = "";
            break;
        case 14:
            display.clearDisplay();
            key = 0;
            buffer = "";
            temp = "";
            break;
        default:
            opr = '0';
            buffer = buffer + String(key);
            key = 0;
        }
        OLED_setup(buffer);
        delay(200);
    }
    OLED_setup(buffer);
}

intmax_t cal(String data)
{
    char *endptr;
    intmax_t num = strtoimax(data.c_str(), &endptr, 10);

    while (*endptr)
    {
        switch (*endptr)
        {
        case '+':
        case '-':
            num = num + strtoimax(endptr, &endptr, 10);
            break;
        case '*':
            endptr++;
            num = num * strtoimax(endptr, &endptr, 10);
            break;
        }
    }
    return num;
}
void key_broad()
{
    for (i = 0; i < 4; i++)
    {
        digitalWrite(row[1], i / 2);
        digitalWrite(row[0], i % 2);
    }
}
void OLED_setup(String data)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(data);
    display.setCursor(0, 0);
    display.display();
}