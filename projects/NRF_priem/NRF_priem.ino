#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);
const uint32_t pipe = 123456789;

byte data[5];

void getData(){
  if (radio.available())
  {
    radio.read(&data, sizeof(data));
    //Serial.println(data);
    Serial.print(data[0]);
    Serial.print("  ");
    Serial.print(data[1]);
    Serial.print("  ");
    Serial.print(data[2]);
    Serial.print("  ");
    Serial.print(data[3]);
    Serial.print("  ");
    Serial.print(data[4]);
    Serial.println();//*/
  }
  else{
    //Serial.println("Faile");
  }
}

void setup()
{
  Serial.begin(9600);
  radio.begin();  
  radio.setDataRate(RF24_1MBPS); // скорость обмена данными RF24_1MBPS или RF24_2MBPS
  radio.setCRCLength(RF24_CRC_8); // длинна контрольной суммы 8-bit or 16-bit
  radio.setPALevel(RF24_PA_MAX); // уровень питания усилителя RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  // соответствует уровням:    -18dBm,      -12dBm,      -6dBM,           0dBm
  radio.setChannel(150);         // уствновка канала
  radio.setAutoAck(false);       // - автоответ.
  radio.powerUp();               // включение или пониженное потребление powerDown - powerUp
  radio.openReadingPipe(1, pipe); // открыть канал на приём
  radio.startListening(); // приём
}


void loop()
{
  getData();  
}
