#include <Servo.h>
Servo myservo;
const int in1 = 2;
const int in2 = 3; 
const int in3 = 4;
const int enA = 6;
const int enB = 6;
const int in4 = 7; 
int trig=8;
int echo=9; // 10 for servo
const int pir = 11;
const int buzzer = 5;
const int red= A1;
const int BUTTON = A2;
const int green_l = A3;
const int green_r = A4;
const int blue = A5;

int cm;
long double duration;
class servo_mod {
  public: 
  int level;
  float distance;
};
servo_mod w_r , w_l, frwd;
int ir_left=12;
int ir_right=13;
int left=0, right=0, motion=1,i=0, button=1, pir_value=0 ;
 int M1_Speed = 120; 
 int M2_Speed = 120;  
 int LeftRotationSpeed = 100;   
 int RightRotationSpeed = 100; 
 void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(ir_left,INPUT);
  pinMode(ir_right,INPUT);
  pinMode(pir,INPUT);
  myservo.attach(10);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  myservo.write(90);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(buzzer,0);

    button=digitalRead(BUTTON);
    if(!button){ while(i==3){
    digitalWrite(A5,1);
    digitalWrite(red,0);
    digitalWrite(buzzer,1);
    delay(1000);digitalWrite(A5,0);
    digitalWrite(red,1);digitalWrite(buzzer,1);
    delay(1000);
    Serial.println("1");
    i++;}
    i=0;
    }
    if(!motion){  myservo.write(0);/*inside a block */ delay(6000);
    pir_value=digitalRead(pir);
   Serial.println("2");
    w_r.distance=calculateDistance();
    if(w_r.distance<=20 && pir_value){
      w_r.level=1;
      digitalWrite(red,1);
      digitalWrite(green_l,0);
    Serial.println("3");}
    else{
 w_r.level=0;
      digitalWrite(red,0);
      digitalWrite(green_l,1);
    Serial.println("7");}
    delay(1000);
    myservo.write(180);/*outside a block */ delay(6000);
    w_l.distance=calculateDistance();
    pir_value=digitalRead(pir);
    if(w_l.distance<=20 && pir_value){
      w_l.level=1;
      Serial.println("4");
      digitalWrite(red,1);
      digitalWrite(green_r,0);
    }
    else{
      w_l.level=0;
      digitalWrite(red,0);
      digitalWrite(green_r,1);
    Serial.println("5");}
    delay(1000);
    if(w_l.level==1 && w_r.level==1){
      motion=1;
      forward();
      Serial.println("0");
      myservo.write(90);
      return ;
          }
    

    
}
else {
  left=digitalRead(ir_left);
  right=digitalRead(ir_right);
  frwd.distance=calculateDistance();
  if(frwd.distance<20){ Stop(); digitalWrite(buzzer,1); Serial.println("89");}
  else if (left && right){Stop();motion=0 ;digitalWrite(red,1);}
  else if (left==0 && right==0) { forward();motion=1;  return;}
  else if(left==0 && right){ right_rotation();motion=1; return;}
  else if(left && right==0){ left_rotation();motion=1; return;}
  else{ Stop();}

}
}
void forward() {
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW); 
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
     analogWrite(enA, M1_Speed);
     analogWrite(enB, M2_Speed);
}

void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, M1_Speed);
  analogWrite(enB, M2_Speed);
}

void right_rotation()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            analogWrite(enA, LeftRotationSpeed);
            analogWrite(enB, RightRotationSpeed);
}

void left_rotation()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enA, LeftRotationSpeed);
            analogWrite(enB, RightRotationSpeed);
}                                                                                                             
void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}

int calculateDistance(){ 
  
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm= duration*0.034/2;
  return cm;
}