
const int analogInPin = A0;
int sensorValue = 0;

void setup() {
Serial.begin(9600);
Serial.println("Microphone Test" );
}

void loop() {
sensorValue = analogRead(analogInPin);
Serial.print("Microphone value= ");
Serial.println(sensorValue);


}

