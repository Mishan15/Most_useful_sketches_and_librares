#define echoPin 8
#define trigPin 9

#define max_millis 50

float duration, cm;
int last_millis;
int distance;

void skanHigh(){  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58.0;
  Serial.print(cm);
  Serial.println();
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  skanHigh();
}
