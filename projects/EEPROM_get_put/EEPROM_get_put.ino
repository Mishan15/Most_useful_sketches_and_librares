#include <EEPROM.h>

int addr, n = 5768;

void setup() {
  Serial.begin(9600);
  addr = 0;
  EEPROM.put(addr, n);
  addr += sizeof(int);
  for (int i = 0; i < 2000; i += 100) {
    Serial.print("put val ");
    Serial.println(i);
    EEPROM.put(addr, i);
    Serial.print("input val ");
    EEPROM.get(addr, n);
    Serial.println(n);
  }
  Serial.print("input control val ");
  addr = 0;
  EEPROM.get(addr, n);
  Serial.println(n);
}

void loop() {
  
}
