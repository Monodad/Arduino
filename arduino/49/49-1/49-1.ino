#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 d = Adafruit_SSD1306(128, 64);
u32 timer_time[3] = {0};
u32 timer(int time) { return millis() - timer_time[time]; };
void set_timer(int time) { timer_time[time] = millis(); };
int voltage = 0;

void setup()
{
    Serial.begin(115200);
    d.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    d.clearDisplay();
    draw();
    d.setTextSize(1);
    d.setTextColor(SSD1306_WHITE);
    d.cp437(true);
    d.display();
    voltage = analogRead(A0);
}
void draw()
{
    d.drawRect(0, 4, 127, 60, 1);
    d.drawFastHLine(0, 31, 127, 1);
    d.drawFastVLine(63, 4, 60, 1);
}
bool isTrigger = false;
bool notTrigger = false;
void trigger()
{
    if (analogRead(A0) > voltage && analogRead(A0) > 338 && map(analogRead(A0), 0, 1023, 60, 4) == 31)
    {
        isTrigger = true;
        notTrigger = false;
    }
    else
    {
        notTrigger = true;
    }
}
u32 scantime = 0;
byte nmsl = 0;

double frequency = 0;
bool scan = true;
int highest = 0;
u32 dis_time = 0;
void loop()
{
    u32 m = micros(), read;

    if (m - scantime >= 156)
    {
        scantime = m;
        read = analogRead(A0);
        if (read >= highest)
        {
            highest = read;
            Serial.println(read);
        }

        if (read > voltage && read >= 348 && map(read, 0, 1023, 60, 4) == 31)
        {
            isTrigger = true;
        }
        if (isTrigger && scan)
        {

            d.writePixel(nmsl, map(read, 0, 1023, 60, 4), WHITE);
            if (read <= 348 && frequency == 0)
                frequency = 280 * nmsl;
            nmsl = nmsl == 128 ? 0 : nmsl + 1;
            scan = nmsl == 128 ? false : true;
        }
        if (nmsl == 128 && m - dis_time > 500'000)
        {
            dis_time = m;
            nmsl = 0;
            isTrigger = false;
            draw();
            d.setCursor(70, 50);
            d.printf("%.1f HZ", 1000000.0 / frequency);
            d.setCursor(10, 50);
            d.printf("%dmV", (map(highest - 530, 0, 1024, 0, 3200)) * 2);
            d.display();
            d.clearDisplay();
            highest = 0;
            frequency = 0;
            scan = true;
        }
        voltage = read;
    }
}
