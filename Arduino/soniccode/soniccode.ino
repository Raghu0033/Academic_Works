const int trigpin = 7;
const int echopin = 8;
const int ledpin = 13;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin, LOW);

  long double duration = pulseIn(echopin, HIGH);

  // convert the time into a distance
  double inches = duration/74/2;
  double cm = duration/29/2;
      
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm<6){
    digitalWrite(ledpin,HIGH);
    
  }
  else{
    digitalWrite(ledpin,LOW);
  }

  delay(1000);
}