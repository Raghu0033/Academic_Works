#include <Servo.h>
Servo myservo;
//char x[5];
int asc,angle,ang=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
myservo.attach(11); 
}

void loop() {
  
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){
  
  while(Serial.available()){
    asc=Serial.read();
    angle=asc-48;
    ang=(ang*10)+angle;
  }

    Serial.println(ang);
   myservo.write(ang);
   ang=0;
   angle=0;
 }

 delay(10);
}
