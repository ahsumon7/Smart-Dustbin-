#include <Servo.h>
int gnd=12;
int echo=10;
int trig=11;
Servo myservo;
int VCC=13;
float duration=0;
float distance=0;
float  height=0;
float level=0;

void setup() {
  Serial.begin(9600);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(VCC,OUTPUT);
  
  pinMode(gnd,OUTPUT);
  digitalWrite(VCC,HIGH);
  digitalWrite(gnd,LOW);
  Serial.println("Distance");
  myservo.attach(9);
  myservo.write(0);
 
}

void loop() {

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration*0.0347)/2;  
  Serial.println(distance);
  delay(1000);

  if(distance<30)
  {
    myservo.write(90);
  }
  else
    myservo.write(0);
}
