#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1302, 7, 5, 6); // RST, CLK, DAT
void setup() {
    delay(300);
    Serial.begin(9600);
    time.begin();
    time.settime(0,44,21,22,12,18,6);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
}
void loop(){
    //if(millis()%1000==0){ // если прошла 1 секунда
    //time.settime(0,44,21,22,12,18,6);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
      Serial.println(time.gettime("d-m-Y, H:i:s, D")); // выводим время
      delay(10); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
    //}
}
