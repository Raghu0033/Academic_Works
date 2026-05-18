const int pinin =A0;
const int pinout =13;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinin,INPUT);
  pinMode(pinout,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rain=analogRead(pinin);
  Serial.print(rain);
  Serial.print("\n");
  if(rain<950){
  digitalWrite(pinout,HIGH);
  }
  else
  {
  
  digitalWrite(pinout,LOW);

}
  delay(1000);



}
