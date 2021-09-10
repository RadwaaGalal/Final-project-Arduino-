#include <Servo.h>
Servo myServo;
int LED = 13;
int LED3 = 9;
const int Echo = 11;
const int Trig = 10;
int LDR = A0;
long Duration;
int Distance;
int Light;
int pos = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT); 
  pinMode(Echo, INPUT);   
  myServo.attach(12); 
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}
void loop() {
 Serial.println("Entry Sensor : ");
 Serial.println(Light);
 Light = analogRead(LDR);
  if (Light < 100 && Distance <= 10){
    digitalWrite(LED, HIGH);
    digitalWrite(LED3, HIGH);
    Serial.println("Night Mode Is On");
    
 }else {
  digitalWrite(LED, LOW);
  digitalWrite(LED3, LOW);
  Serial.println(" light Mode Is On ");
  }
  
  for(int pos=0; pos <= 180 ; pos++){  
  myServo.write(pos);
  delay(10);
  Distance = Add_Distance();
  Serial.print(pos); 
  Serial.print("  "); 
  Serial.print(Distance); 
  }
  
  
  for(int pos = 180 ; pos >= 0 ; pos--){  
  myServo.write(pos);
  delay(20);
  Distance = Add_Distance();
  Serial.print(pos);
  Serial.print("  ");
  Serial.print(Distance);
  }
}


int Add_Distance(){ 
  digitalWrite(Trig, LOW); 
  delayMicroseconds(2);
  
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  Duration = pulseIn(Echo, HIGH); 
  Distance= Duration*0.034/2;
  return Distance;
}
