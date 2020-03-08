void analog_scan(){
  for(byte i = A0; i <= A7; i++) {
    Serial.print(analogRead(i));
    Serial.print("  ");
  }
}

void digital_scan(){
  for(byte i = A0; i <= A7; i++) {
    Serial.print(digitalRead(i));
    Serial.print("  ");
  }
}

void setup() {
  Serial.begin(9600);
  //for(byte i = A0; i <= A7; i++) pinMode(i, INPUT_PULLUP);
  Serial.println("ready");
}

void loop() {
  analog_scan();
  Serial.println();
}
