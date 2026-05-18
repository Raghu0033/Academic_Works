#include <string.h>
const int tank_trig_pin = 7;
const int tank_echo_pin = 8;
const int sump_trig_pin = 2;
const int sump_echo_pin = 4;
const int m1=11;
const int m2=12;
char i;

String MValue(int A1){
  if (A1==HIGH){
    return "OFF";
  }
  else if (A1==LOW){
    return "ON";
  }
}

class  level {
  public: 
  float percent;
  double cm;
  double lit;
  long double duration;
  float height;
  //for cylinder  eg:blue tanks
  float radius;    //enter in cm for testing
  double volume(int altitude)  { return 3.14*altitude*radius*radius; }
  /*
  //for Cubiod
  float length;
  float breadth;
  double volume(int altitude) { return length*altitude*breadth; }
  */
  float water_level_percent() { percent = (volume(cm)/volume(height))*100; lit=(volume(height)-volume(cm))/1000;  return percent; }

  double water_level(int trig_pin,int echo_pin){
    digitalWrite(trig_pin , LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin , HIGH);
    delayMicroseconds(5);
    digitalWrite(trig_pin , LOW);
    duration = pulseIn(echo_pin, HIGH);
    cm = (duration/2)/29.1;
    water_level_percent();
    return cm; }
  
};

  level tank; level sump;
void setup() {
  Serial.begin(9600);
  pinMode(sump_trig_pin,OUTPUT);
  pinMode(sump_echo_pin,INPUT);
  pinMode(tank_trig_pin,OUTPUT);
  pinMode(tank_echo_pin,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  tank.radius=50; //centimeters
  tank.height=200;//centimeters
  sump.radius=50; //centimeters
  sump.height=200;//entimeters
  digitalWrite(m2,HIGH);
  digitalWrite(m1,HIGH);
}

void loop() {
   int m11= digitalRead(m1);
   int m21= digitalRead(m2);
  tank.water_level (tank_trig_pin,tank_echo_pin);
  sump.water_level (sump_trig_pin,sump_echo_pin);
  //Serial.println("Tank level:");
  //Serial.println(tank.percent);
  //Serial.println("Sump level:");
  //Serial.println(sump.percent);
  //Serial.println(tank.cm);
  //Serial.println(sump.cm);
  if ((Serial.available()|| i=='1' || i=='2')&& tank.percent>10){
     i=Serial.read();
    if (i=='1'){
      digitalWrite(m2,HIGH);
      digitalWrite(m1,LOW);
    }
    else if(i=='2'){digitalWrite(m2,LOW);
    digitalWrite(m1,HIGH);}
    if (tank.percent<10){
      i='0';
    }
  }
  else{
if ( tank.percent<90 && m11 == 1 && m21 == 1 )  { }
else if ((m11==0 || m21==0) && tank.percent<10){
  digitalWrite(m2,HIGH);
  digitalWrite(m1,HIGH);
}
else{
  if (sump.percent>85){
    digitalWrite(m2,LOW);
    digitalWrite(m1,HIGH);
    }
  else if (m21==0 && sump.percent>50){
    digitalWrite(m2,HIGH);
    digitalWrite(m1,LOW);
  }
  else if (tank.percent>90 ){
    digitalWrite(m2,HIGH);
    digitalWrite(m1,LOW);
  }}
  }
   m11= digitalRead(m1);
   m21= digitalRead(m2);

// bluetooth including using TX and RX
 // Serial.pr 
  Serial.println(MValue(m11));
  Serial.print("Under Ground Motor is ");
  Serial.println(MValue(m21));
  if(m11 == 0 || m21 == 0){
  Serial.println("Enter \'1\' To Turn On Sump Motor \n Enter \'2\' To Turn On Ground Motor");
  }
  delay(5000);
  
  } 

