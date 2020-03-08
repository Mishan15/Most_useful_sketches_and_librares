#include <IRremote.h>         // библиотека для ИК
#define RECV_PIN 5
IRrecv irrecv(RECV_PIN);      // создаем объект получения сигнала с заданного порта
decode_results results;       // переменная хранящая результат

int w;

void setup() {
  Serial.begin(9600);
  //pinMode(5,OUTPUT); digitalWrite(5,LOW);
  irrecv.enableIRIn();    // включаем ИК-приемник 
  Serial.println("Hello world");
}

void loop() {
 if (irrecv.decode(&results)) {    
    w = results.value;
    Serial.println(w,HEX);
    irrecv.resume();    // получаем следующее значение
  };
}
/*
 * 0 6897
 * 1 30CF
 * 2 18E7
 * 3 7A85
 * 4 10EF
 * 5 38C7
 * 6 5AA5
 * 7 42BD
 * 8 4AB5
 * 9 52AD
 * EQ FFFF906F
 * VOL- FFFFE01F
 * VOL+ FFFFA857
 * PREV 22DD
 * NEXT 2FD
 * PLAY/PAUSE FFFFC23D
 * CH- FFFFA25D
 * CH 629D
 * CH+ FFFFE21D
 */
 
// 0 6897
// 1 30CF
// 2 18E7
// 3 7A85
// 4 10EF
// 5 38C7
// 6 5AA5
