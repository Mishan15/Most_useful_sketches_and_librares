/*
 * conected:
 * GND -> GND
 * VCC -> 5V
 * SDA -> A4
 * SCL -> A5
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define addr 0x3F// for old 0x27 , for new 0x3F
LiquidCrystal_I2C lcd(addr,16,2);  // Устанавливаем дисплей

int time1;
byte S1[7]={30,31,31,31,31,31,30};

void setup(){
  Serial.begin(9600);
  lcd.init(); 
  lcd.createChar(0,S1);              
}

void loop(){        
  lcd.backlight();// Включаем подсветку дисплея
  lcd.setCursor(0, 0);
  lcd.print("Test LCD 1602");
  lcd.setCursor(0, 15);
  lcd.write(byte(0));
  lcd.setCursor(8, 1);
  lcd.print("seconds");
  time1=millis()/1000;
  lcd.setCursor(0, 1);
  lcd.print(time1);
  Serial.print("addr: "); Serial.print(addr,HEX); Serial.print(" second: "); Serial.println(time1);
}
