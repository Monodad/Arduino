#include <ESP8266WiFi.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
Servo s;
#define SS_PIN D8
#define RST_PIN D0
MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;
byte nuidPICC[4];
Adafruit_SSD1306 d = Adafruit_SSD1306(128, 64);
char ssid[] = "WeMos";
char pass[] = "12345678";
int pre_time = 0;
IPAddress ip(192, 168, 0, 50);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
WiFiServer server(80);
void setup()
{
    s.attach(D4);
    Serial.begin(115200);
    d.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    d.display();
    init_UID();
    // WiFi.config(ip, gateway, subnet);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }
    Serial.print("Connected");
    Serial.println(WiFi.localIP());
    server.begin();

    d.clearDisplay();
    d.setTextSize(1);
    d.setTextColor(SSD1306_WHITE);
    d.setCursor(0, 0);
    d.cp437(true);
    d.println("IP : 192.168.0.188");
    d.display();
    d.clearDisplay();
    d.display();
    pre_time = millis();
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
}
int hour = 0, min_t = 0, pre_time1 = 0, pre_read = 0;
int8_t mode = 0;
int brzee_enter = 0, brzee_error_t;
int hour_temp, min_temp;
bool load = 0, error = 0, brzee_status = 0, enter = 0, out = 0, add = 0;
int money = 100;
char time_buffer[50];
int bottom;

void loop()
{
    unsigned long m = millis(), n = m, brzee_time = m;
    WiFiClient client = server.available();
    if (bottom < 10)
    {
        read_UID();
        pre_time1 = millis();
        mode = 1;
    }
    else if (bottom > 300 && bottom < 400)
    {
        read_UID();
        mode = 2;
    }
    else if (bottom > 700 && bottom < 900)
    {
        read_UID();
        add = 0;
        mode = 3;
    }
    if (load == 1 && enter == 1)
    {
        if (millis() - brzee_enter <= 200)
        {
            brzee_status = 1;
            s.write(0);
        }
        else
        {
            if (millis() - brzee_enter >= 1200)
            {
                s.write(180);
                enter = 0;
            }

            brzee_status = 0;
        }
    }
    if (error == 1)
    {
        brzee_error();
    }
    if (m - pre_time >= 1000)
    {
        bottom = read();

        pre_time = m;
        min_t++;
        if (min_t == 60)
        {
            hour++;
            if (hour == 24)
            {
                hour = 0;
            }
            min_t = 0;
        }
        d.clearDisplay();
        d.setCursor(90, 0);
        if (hour < 10)
        {
            d.print("0");
            d.print(hour);
        }
        else
            d.print(hour);

        d.print(":");

        if (min_t < 10)
        {
            d.print("0");
            d.println(min_t);
        }
        else
            d.println(min_t);

        if (load == 1 && out == 0)
        {
            d.setCursor(0, 30);
            d.println(time_buffer);
        }
        if (load == 1 && out == 1)
        {
            d.setCursor(0, 10);

            if (add == 1)

                d.println("PLEASE ADD CREDIT");

            else
                d.println(time_buffer);
        }

        d.display();
    }
    digitalWrite(D3, brzee_status);
    if (client)
    {
        client.printf(R"====(
<html>
 <head>
  <meta http-equiv="refresh" content="5">
</head>
<body>

    <h>PARKING FEE</h>
    <p>%s</p>
</body>
</html>
)====",
                      time_buffer);
        client.stop();
    }
}
void init_UID()
{
    SPI.begin();     // Init SPI bus
    rfid.PCD_Init(); // Init MFRC522

    for (byte i = 0; i < 6; i++)
    {
        key.keyByte[i] = 0xFF;
    }
}
void read_UID()
{
    if (!rfid.PICC_IsNewCardPresent())
        return;

    // Verify if the NUID has been readed
    if (!rfid.PICC_ReadCardSerial())
        return;

    Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
    Serial.println(rfid.PICC_GetTypeName(piccType));

    // Check is the PICC of Classic MIFARE type
    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K)
    {
        Serial.println(F("Your tag is not of type MIFARE Classic."));
        return;
    }

    if (rfid.uid.uidByte[0] != nuidPICC[0] ||
        rfid.uid.uidByte[1] != nuidPICC[1] ||
        rfid.uid.uidByte[2] != nuidPICC[2] ||
        rfid.uid.uidByte[3] != nuidPICC[3])
    {
        Serial.println(F("A new card has been detected."));

        // Store NUID into nuidPICC array
        if (load == 0)
        {
            brzee_enter = millis();
            load = 1;
            enter = 1;

            sprintf(time_buffer, "IN : %02d:%02d \nBAL : %d", hour, min_t, money);
            hour_temp = hour;
            min_temp = min_t;
            for (byte i = 0; i < 4; i++)
            {
                nuidPICC[i] = rfid.uid.uidByte[i];
            }
        }
        else
        {
            sprintf(time_buffer, "CARD ERROR !");
            error = 1;
            brzee_status = 1;
            brzee_error_t = millis();
        }
    }
    else
    {
        Serial.println(F("Card read previously."));
        enter = 1;
        if (mode == 1)
        {
            sprintf(time_buffer, "IN : %02d:%02d \nBAL : %d", hour, min_t, money);
            hour_temp = hour;
            min_temp = min_t;
            brzee_enter = millis();
            enter = 1;
        }
        if (mode == 2)
        {

            out = 1;
            int FEE = 0, i = 0;
            int time = (hour - hour_temp) * 60 + (min_t - min_temp);
            while (time > 0)
            {
                i++;
                time = time - 30;
            }
            FEE = i * 20;

            if (money - FEE >= 0)
            {
                money = money - FEE;
                sprintf(time_buffer, "IN : %0d:%0d\nOUT: %0d:%0d\nFEE: %0d\nBAL: %d", hour_temp, min_temp, hour, min_t, FEE, money - FEE);
            }
            else
            {
                add = 1;
            }
        }
        if (mode == 3)
        {
            money = money + 100;
            add = 0;
            sprintf(time_buffer, "ADD : %d\nBAL : %d", 100, money);
        }
        brzee_enter = millis();
    }

    // Halt PICC
    rfid.PICC_HaltA();

    // Stop encryption on PCD
    rfid.PCD_StopCrypto1();
}

int count = 0;

void brzee_error()
{
    if (millis() - brzee_error_t >= 50 && brzee_status)
    {
        brzee_error_t = millis();
        brzee_status = !brzee_status;
        count++;
    }
    if (millis() - brzee_error_t >= 100 && !brzee_status)
    {
        brzee_error_t = millis();
        brzee_status = !brzee_status;
    }
    if (count == 3)
    {
        brzee_status = 0;
        error = 0;
        count = 0;
    }
}

int read()
{
    return analogRead(A0);
}