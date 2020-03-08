/*
   Схема подключения:
   * Аналоговые сенсоры подключаются к аналоговым пинам
   * Модуль SD карты подключен в SPI по стандартной схеме:
   ** MOSI - пин 11
   ** MISO - пин12
   ** CLK - пин 13
   ** CS - pin 4
   */
  
#include <SPI.h>
#include <SD.h>

const int PIN_CHIP_SELECT = 4;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(4,OUTPUT);
  if (!SD.begin(PIN_CHIP_SELECT)) {
    Serial.println("Card failed, or not present");
    return;
  }
  
  Serial.println("card initialized.");
}

void loop() {
String logStringData="";
//logStringData=String(analogRead(A0));
   /* File dataFile = SD.open("datalog.csv", FILE_WRITE);
    if(dataFile) {
      dataFile.println(logStringData);
      dataFile.close();
    Serial.println(logStringData);
  }
  else {
    Serial.println("error opening datalog.csv");
  }*/
  File dataFile = SD.open("datalog.csv", FILE_READ);
    if(dataFile) {
          Serial.println(dataFile.read());
          dataFile.close();
  }
  else {
    Serial.println("error opening datalog.csv");
  }
}

