#include <SPI.h>
#include <RFID.h>

// Константы подключения контактов RST и SS 
#define SS_PIN 10
#define RST_PIN 9
 
RFID rfid(SS_PIN, RST_PIN); 
 
int serNum[5];

// Подключение к контактам rgb-светодиода
const byte rPin = 6;
const byte gPin = 5;
const byte bPin = 3;
 
void setup()
{ 
    Serial.begin(9600);            // Инициализация монитора
    SPI.begin();                   // Инициализация SPI шины
    rfid.init();                   // Инициализация RC522

    pinMode( rPin, OUTPUT );
    pinMode( gPin, OUTPUT );
    pinMode( bPin, OUTPUT );
}
 
void loop()
{
    // Если обнаружена метка
    if (rfid.isCard()) {
        // Считываем данные
        if (rfid.readCardSerial()) {
          // Проверка данных
          if ((rfid.serNum[0] == 0xE1)&&(rfid.serNum[1] == 0x54)&&(rfid.serNum[2] == 0x5A)&&(rfid.serNum[3] == 0x2D)&&(rfid.serNum[4] == 0xC2))
          {
            // Если ID карты совпал, вывести надпись "Access granted!", ID карты и подать зелёный сигнал на светодиод
            Serial.println("Access granted!");
            Serial.println("Card number:");
            Serial.print(rfid.serNum[0],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[1],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[2],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[3],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[4],HEX);
            Serial.println(" ");

            digitalWrite( rPin, LOW );
            digitalWrite( bPin, LOW );
            digitalWrite( gPin, HIGH );
          }
          else
          {
            // Если ID карты не верен, вывести "Wrong ID!", ID карты и подать красный сигнал на светодиод
            Serial.println("Wrong ID!");
            Serial.println("Card number:");
            Serial.print(rfid.serNum[0],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[1],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[2],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[3],HEX);
            Serial.print(" ");
            Serial.print(rfid.serNum[4],HEX);
            Serial.println(" "); 

            digitalWrite( bPin, LOW );
            digitalWrite( gPin, LOW );
            digitalWrite( rPin, HIGH );
          }

            delay(1000);
            digitalWrite( bPin, LOW );
            digitalWrite( gPin, LOW );
            digitalWrite( rPin, LOW );
        }       
    }
    rfid.halt();
}
