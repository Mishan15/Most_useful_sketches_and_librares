#define Delay 500
#define ledPin1 13
#define ledPin2 12
#define GNDPin 11

#define usual 0

void setup() {
  Serial.begin(9600);
  if(usual) pinMode(13,OUTPUT);
  else{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
}


void loop() {
  if(usual){
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
  }else{
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2, LOW);
    delay(1000);
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2, HIGH);
    delay(1000);
  }
  /*for(int i=11; i>6;i-=2){
    Serial.print(digitalRead(i));
    Serial.print("  "); 
    }
    Serial.println();
  /*digitalWrite(ledPin1, HIGH); 
  delay(Delay); 
  digitalWrite(ledPin2, HIGH);
  delay(Delay);                       
  digitalWrite(ledPin1, LOW);
  delay(Delay);  
  digitalWrite(ledPin2, LOW); 
  delay(Delay);//*/                      
}
