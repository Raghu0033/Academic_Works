const int pirpin=8;
const int relaypin=7;
const int ldrpin=4;
//const int spin=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(relaypin,OUTPUT);
  pinMode(pirpin,INPUT);  
  pinMode(ldrpin,INPUT);
  //pinMode(spin,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
 int pirvalue=digitalRead(pirpin);
 int ldrvalue=digitalRead(ldrpin);
 //int s=digitalRead(spin);
 if ( ldrvalue == 1 || pirvalue == 1 ){
 digitalWrite(relaypin,HIGH);
 }
 else{
  digitalWrite(relaypin,LOW);
 }
}
