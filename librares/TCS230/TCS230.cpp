#include "Arduino.h"
#include "TCS230.h"
#include "EEPROM.h" 
int g_count = 0;	
TCS230::TCS230(int s0, int s1, int s2, int s3, int out, int emit){
  this->s0 = s0;
  this->s1 = s1;
  this->s2 = s2;
  this->s3 = s3;
  this->out = out;
  this->emit = emit;
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(emit, OUTPUT);  
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH); 
  g_array[0] = 0;
  g_array[1] = 0;
  g_array[2] = 0;
  g_flag = 0;
  period = 500;	
}
TCS230::TCS230(){
  this->s0 = 49;
  this->s1 = 48;
  this->s2 = 50;
  this->s3 = 51;
  this->out = 18;
  this->emit = 19;
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(emit, OUTPUT);  
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH); 
  g_array[0] = 0;
  g_array[1] = 0;
  g_array[2] = 0;
  g_flag = 0;
 period = 200;
} 
RGBM TCS230::getColorCalibrate() {
  RGBM color;	
  attachInterrupt(5, TSC_Count, RISING);
  g_flag = 0;
  for (int i = 0; i < 4; i++) {
    TSC_Callback();
    delay(period);
  }
  detachInterrupt(5);
  float g_SF[3];
  EEPROM.get(0, g_SF[0]);
  EEPROM.get(4, g_SF[1]);
  EEPROM.get(8, g_SF[2]);
  color.R = g_array[0] * g_SF[0];
  color.G = g_array[1] * g_SF[1];
  color.B = g_array[2] * g_SF[2];
  color.M = (color.R+color.G+color.B) / 3;
  color.M = (color.M*100.0)/255.0;
  if (color.M>100) color.M=100;
  g_count = 0;
  return color;  
}
RGBM TCS230::getColor() {
  RGBM color;	
  attachInterrupt(5, TSC_Count, RISING);
  g_flag = 0;
  for (int i = 0; i < 4; i++) {
    TSC_Callback();
    delay(period);
  }
  detachInterrupt(5);
  color.R = g_array[0];
  color.G = g_array[1];
  color.B = g_array[2];
  color.M = (color.R+color.G+color.B) / 3;
  g_count = 0;
  return color;  
}
void TCS230::colorCalibrated() {
  delay(1000);
  attachInterrupt(5, TSC_Count, RISING);
  for (int i = 0; i < 4 ; i ++) {
    TSC_Callback();
    delay(period);
  }
  float g_SF[3];
  g_SF[0] = 255.0 / g_array[0]; //R коэффициент
  g_SF[1] = 255.0 / g_array[1] ; //G коэффициент
  g_SF[2] = 255.0 / g_array[2] ; //B коэффициент
  EEPROM.put(0, g_SF[0]); // записали число f по адресу addr 
  EEPROM.put(4, g_SF[1]);
  EEPROM.put(8, g_SF[2]);
  detachInterrupt(5);
}
void TCS230::TSC_FilterColor(int Level01, int Level02)
{
  if (Level01 != 0)
    Level01 = HIGH;
  if (Level02 != 0)
    Level02 = HIGH;
  digitalWrite(s2, Level01);
  digitalWrite(s3, Level02);
}

void TCS230::TSC_Callback()
{
  switch (g_flag)
  {
    case 0:
      TSC_WB(LOW, LOW); //Фильтр без красного
      break;
    case 1:
      g_array[0] = g_count;
      TSC_WB(HIGH, HIGH); //Фильтр без зеленого
      break;
    case 2:
      g_array[1] = g_count;
      TSC_WB(LOW, HIGH); //Фильтр без синего
      break;
    case 3:
      g_array[2] = g_count;
      TSC_WB(HIGH, LOW); //Очистка
      break;
    default:
      g_count = 0;
      break;
  }
}
void TSC_Count(){
	g_count++;
}
void TCS230::TSC_WB(int Level0, int Level1) //Баланс белого
{
  g_count = 0;
  g_flag ++;
  TSC_FilterColor(Level0, Level1);
}
