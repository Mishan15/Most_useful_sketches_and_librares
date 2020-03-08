#include <Wire.h>// подключаем библиотеки
#include "HMC5883L.h"  // для компаса
#include <LiquidCrystal.h>// и дисплея
HMC5883L compass;
// тут выводы для подключения дисплея
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //
int Data;
void setup() {

  Wire.begin();
  lcd.begin(16, 2);//инициализация дисплея
  lcd.print("< DV-ROBOT >");// реклама магазина))
  delay(2000);
  compass.SetMeasurementMode(Measurement_Continuous); //устанавливаем непрерывный режим работы компаса
}

void loop() {
  lcd.setCursor(0, 1);// устанавливаем курсор
  float heading = getHeading();
  Data  =    heading / 1.00; // избавлемся от знаков после запятой (округляем до целого числа)
  lcd.clear(); //очищаем дисплей от предыдущего значения
  lcd.print(Data);// выводим на дисплей новое значение
  delay(250); // обновляем значение на дисплее через 0,25секунд
}

float getHeading() {
  // основная функция считывания данных с компаса и расчета  направления
  MagnetometerScaled scaled = compass.ReadScaledAxis(); // получаем значения с датчика
  float heading = atan2(scaled.YAxis, scaled.XAxis);    // расчет направления поворота

  // корректируем значения с учетом знаков
  if (heading < 0) heading += 2 * PI;
  if (heading > 2 * PI) heading -= 2 * PI;

  return heading * RAD_TO_DEG; // переводим радианы в удобные для восприятия градусы 0-360
}
