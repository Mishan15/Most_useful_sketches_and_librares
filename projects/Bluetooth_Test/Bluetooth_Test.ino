#include <Arduino.h>
#include <SoftwareSerial.h>

#define Led 13

SoftwareSerial BT(6, 7); //first_pin, second_pin
// connect BT module TX to first_pin
// connect BT module RX to second_pin
// connect BT Vcc to 5V, GND to GND

char data;

void setup()
{
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  BT.begin(9600);
  BT.println("Hello from Arduino");
  BT.println("Привет от ардуино");
  //pinMode(12, OUTPUT);
  //digitalWrite(12, LOW);
  //digitalWrite(13, HIGH);
}


void loop() {
  if (BT.available()) {
    data = (BT.read());
    BT.println(data);
    if(data == '1') digitalWrite(Led, HIGH);
    else if(data == '0') digitalWrite(Led, LOW);
  }
}
