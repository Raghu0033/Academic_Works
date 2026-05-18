const int soilangin=A0; rainangin=A1; pirdigin=1; ulsctrigout=1; ulscechoin=2
const int alertout=13; waterout=12; motoron=11;
 void setup() {
  // put your setup code here, to run once:
  pinMode(soilangin,INPUT);
  pinMode(rainangin,INPUT);
  pinMode(pirdigin,INPUT);
  pinMode(ulscechoin,INPUT);
  pinMode(ulsctrigout,OUTPUT);
  pinMode(alertout,OUTPUT);
  pinMode(waterout,OUTPUT);
  pinMode(motoron,OUTPUT)
  int time=0,rain,soil,ulsc,pir;
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin, LOW);
  long double duration = pulseIn(echopin, HIGH);
 // convert the time into a distance
 //double inches = duration/74/2;
  double cm = duration/29/2;
//   time=time_fun();
rain=analogRead(rainangin);
soil=analogRead(soilangin);
pir=digitalRead(pirdigin);
if(intime==1){
//for irrigation
if(rain<700){
  digitalWrite(waterout,LOW);
}
else if(soil<600)
else
{  digitalWrite(waterout,HIGH);
}

//for motor
if(cm<3)
digitalWrite(motoron,LOW);
else
digitalWrite(motoron,HIGH);


}
}
