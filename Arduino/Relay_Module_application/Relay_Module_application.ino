const int relaypin=8;
//const int ldrpin=5;
int pirvalue=0;
int ldrvalue=0;
//const int spin=4;

void setup() {
  // put your setup code here, to run once:pinMode(relaypin,OUTPUT);
pinMode(relaypin,OUTPUT);

}

void loop() {
// put your main code here, to run repeatedly:

digitalWrite(relaypin,HIGH); 
delay(2000);

 digitalWrite(relaypin,LOW);
 delay(2000);
}
