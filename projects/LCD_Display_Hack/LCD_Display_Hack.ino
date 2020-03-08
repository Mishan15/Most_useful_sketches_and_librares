/*
 * conected:
 * GND -> GND
 * VCC -> 5V
 * SDA -> A4
 * SCL -> A5
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define addr 0x27 // for old 0x27 , for new 0x3F

int adr = 0; int time1;

void setup(){
  Serial.begin(9600);
}

void loop(){
  LiquidCrystal_I2C lcd(adr,16,2);  // Устанавливаем дисплей
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Test LCD 1602");
  lcd.setCursor(8, 1);
  lcd.print("seconds");
  time1=millis()/1000;
  lcd.setCursor(0, 1);
  lcd.print(time1);
  Serial.print("adr: "); Serial.print(adr,HEX); Serial.print(" second: "); Serial.println(time1);
  adr++;
}
