int moisture = A0;
int pinout=13;
int LEDout=8;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(pinout, OUTPUT);
  pinMode(8, OUTPUT);
  
}

void loop()
{
 moisture=analogRead(A0);
  Serial.println(moisture);
   if(moisture<1000){
  digitalWrite(pinout,HIGH);
  }
  else if(moisture<950)
  {
    digitalWrite(8,HIGH);
  }
  else
  {
  
  digitalWrite(pinout,LOW);
  digitalWrite(LEDout,LOW);
}
  delay(1000); 
}