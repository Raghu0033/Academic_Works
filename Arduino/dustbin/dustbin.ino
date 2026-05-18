#include<Servo.h>
Servo Door;
const int trigpin=7;
const int echopin=8;
const int irpin=5;
long double duration;
long double object;
int level;
int door_condition;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(irpin,INPUT);
  pinMode(0,INPUT);
  pinMode(1,OUTPUT);
  Door.attach(9);
  Serial.begin(9600);
}
void loop() {
   if(Serial.available()){
  door_condition=Serial.read();
}
if(door_condition=='1'){
  Door.write(120);delay(1000);return;
}
else if (door_condition=='0'){
  Door.write(0);delay(1000);
}

 level=digitalRead(irpin);
if (level==0){
  Serial.println("Dust Bin is Filled \n Please Clean It");
  delay(1000);
  return;
}
  digitalWrite(trigpin,0);
  delayMicroseconds(2);
  digitalWrite(trigpin,1);
  delayMicroseconds(5);
  digitalWrite(trigpin,0);
  duration=pulseIn(echopin,1);
  object=duration/58.2;
  if(object<50){
    Door.write(90);
  }
  else{
    Door.write(0);
  }
 

delay(1000);
}
