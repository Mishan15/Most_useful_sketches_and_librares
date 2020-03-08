#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo_one;

void attach_one(byte s0){
  servo_one.attach(s0);
}

void attach_all(byte s1, byte s2, byte s3, byte s4, byte s5){
  servo1.attach(s1);
  servo2.attach(s2);
  servo3.attach(s3);
  servo4.attach(s4);
  servo5.attach(s5);
}

void test_one(){
  int r; 
  for (r = 0; r <= 180; r++) {
      servo_one.write(r);
      delay(10);
      Serial.println(r);
    }
    for (r = 180; r > 0; r--) {
      servo_one.write(r);
      delay(10);
      Serial.println(r);
    }
}

void test_more(int q) {
  if (q == 1) {
    int r;
    for (r = 0; r <= 180; r++) {
      servo1.write(r);
      servo2.write(r);
      servo3.write(r);
      servo4.write(r);
      servo5.write(r);
      delay(10);
      Serial.println(r);
    }
    for (r = 180; r > 0; r--) {
      servo1.write(r);
      servo2.write(r);
      servo3.write(r);
      servo4.write(r);
      servo5.write(r);
      delay(10);
      Serial.println(r);
    }
  }
}

void dance() {
  servo1.write(90);
  servo2.write(180);
  servo3.write(180);
  servo4.write(180);
  delay(500);
  servo1.write(180);
  servo2.write(90);
  servo3.write(180);
  servo4.write(180);
  delay(500);
  servo1.write(180);
  servo2.write(180);
  servo3.write(90);
  servo4.write(180);
  delay(500);
  servo1.write(180);
  servo2.write(180);
  servo3.write(180);
  servo4.write(90);
  delay(500);
}

void setup() {
  attach_one(7);
  Serial.begin(9600);
}

void loop() {
  test_one();
}
