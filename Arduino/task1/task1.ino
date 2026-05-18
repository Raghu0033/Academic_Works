#include<string.h>

const int soilangin=A0; 
const int rainin=A1; 
const int ulsctrigout=7; 
const int ulscechoin=8;
 void setup() {
  // put your setup code here, to run once:
  pinMode(soilangin,INPUT);
  pinMode(rainin,INPUT);
 // pinMode(pirdigin,INPUT);
  pinMode(ulscechoin,INPUT);
  pinMode(ulsctrigout,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  }

void loop() {

  digitalWrite(4,HIGH);
  // put your main code here, to run repeatedly:
  digitalWrite(ulsctrigout, LOW);
  delayMicroseconds(2);
  digitalWrite(ulsctrigout, HIGH);
  delayMicroseconds(5);
  digitalWrite(ulsctrigout, LOW);
  long double duration = pulseIn(ulscechoin, HIGH);
  // convert the time into a distance
  //double inches = duration/74/2;
   double cm = duration/29/2;

     int rain,soil,ulsc;
  char x4[10]="WET";
  char x3[50]="LIGHTLY WET";
  char x2[50]="MEDIUM WET";
  char x1[10]="DRY";
  char y4[50]="heavly RAINing";
  char y3[50]="lightly RAINing";
  char y2[50]="looks like RAIN will start";
  char y1[10]="No Rain";

rain=analogRead(rainin);
soil=analogRead(soilangin);


//If moisture >=800
//
//
if(soil>=800){ Serial.println(x4); }
else if(600>soil && soil<799){ Serial.println(x2);}
else if(400<soil && soil<500){ Serial.println(x3);}
else if(soil<400){ Serial.println(x1);}
else{ Serial.println(soil);}

if(rain>=800){ Serial.println(y1); }
else if(600>rain && rain<799){ Serial.println(y2);}
else if(400<rain && rain<500){ Serial.println(y3);}
else if(rain<400){ Serial.println(y4);}
else{ Serial.println(rain);}
//Serial.println(cm);
if(3<cm && cm<10){Serial.println("Object is detected in range");}
else{Serial.println("Object is not detected in range");}

Serial.println("    ");
delay(1000);
}
