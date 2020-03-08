#include <SPI.h>
#include <RF24.h>

RF24 radio(10, 9); // можно использовать любые (порты 15-19 CSN CE MOSI MISO SCK)

const uint32_t pipe = 123456789; // адрес в канале

//char data[6] = {'1', '2' , '3' , '4', '5', '\n'};
int data[3]={654,77,790};

void setup()
{
  //pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);
  radio.begin();                // старт
  //delay(2000);
  radio.setDataRate(RF24_1MBPS); // скорость обмена данными RF24_1MBPS или RF24_2MBPS
  radio.setCRCLength(RF24_CRC_8); // длинна контрольной суммы 8-bit or 16-bit
  radio.setPALevel(RF24_PA_MAX); // уровень питания усилителя RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  // соответствует уровням:    -18dBm,      -12dBm,      -6dBM,           0dBm
  radio.setChannel(150);         // установка канала
  radio.setAutoAck(false);       // - автоответ.
  radio.powerUp();               // включение или пониженное потребление powerDown - powerUp
  radio.openWritingPipe(pipe);   // открыть канал на отправку
}


void loop()
{
  //data[0] = digitalRead(A0) ;
  //data[1] = map(analogRead(A1), 0, 1024, 0, 255);
  //data[2] = map(analogRead(A2), 0, 1024, 0, 255);
  data[2]=millis();
  radio.write(&data, sizeof(data));
  Serial.print(data[0]);
  Serial.print("  ");
  Serial.print(data[1]);
  Serial.print("  ");
  Serial.print(data[2]);
  Serial.println();//*/
  //delay(500);//
}
