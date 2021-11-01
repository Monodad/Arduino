#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
int HZ = 1000;
int sampling_cycle = (1000000 / (HZ)) * (2.0 / 128.0);
int64_t pre_time = 0, times = 0;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
int buffer[128];
void draw_line()
{
    display.drawFastHLine(2, 2, 123, SSD1306_WHITE);
    display.drawFastHLine(2, 32, 123, SSD1306_WHITE);
    display.drawFastHLine(2, 62, 123, SSD1306_WHITE);
    display.drawFastVLine(2, 2, 61, SSD1306_WHITE);
    display.drawFastVLine(64, 2, 61, SSD1306_WHITE);
    display.drawFastVLine(125, 2, 61, SSD1306_WHITE);
    display.display();
}

int read() { return map(analogRead(A0), 0, 1023, 0, 32); }
void setup()
{
    Serial.begin(115200);
    pinMode(A0, INPUT);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    display.clearDisplay();
    draw_line();
}
int trigger = 338, pre_voltage = 0;
int start;
void loop()
{
    unsigned long m = micros(), n = m, current_volage = analogRead(A0);

    if (current_volage < trigger && pre_voltage > current_volage)
    {
        start = 1;
    }

    if (m - pre_time >= sampling_cycle && start == 1)
    {
        pre_time = m;
        for (int i = 0; i < 127; i++)
            buffer[i] = buffer[i + 1];
        buffer[127] = read();
        times++;
    }

    if (times == 128)
    {
        times = 0;
        start = '0';
        display.clearDisplay();
        for (int i = 2; i <= 129; i++)
        {
            display.drawPixel(i, buffer[i - 2], WHITE);
        }

        draw_line();
    }

    pre_voltage = analogRead(A0);
}
