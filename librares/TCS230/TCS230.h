/*
  TCS230.h - библиотека для датчика цвета .
*/
#ifndef TCS230_h
#define TCS230_h
#include "Arduino.h"
 struct RGBM
{
  int R;
  int G;
  int B;
  int M;
};
   
class TCS230
{
  public:
    TCS230(int s0, int s1, int s2, int s3, int out, int emit);
	TCS230();
	RGBM getColor();
	RGBM getColorCalibrate();
	void colorCalibrated();
  private:
    int s0;
	int s1;
	int s2;
	int s3;
	int out;
	int emit;
	int g_array[3];
	int g_flag;
	int period;	
	void TSC_FilterColor(int Level01, int Level02);
	void TSC_Callback();
	void TSC_WB(int Level0, int Level1);
};
void TSC_Count();
#endif
