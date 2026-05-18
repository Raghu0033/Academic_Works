#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(10, 11); // TX | RX
int STATE=9;
 
void setup()
{
  pinMode(9, OUTPUT);
  digitalWrite(STATE, HIGH);
  Serial.begin(38400);
  Serial.println("Waiting : ");
  BTSerial.begin(38400);  
}
 
void loop()
{
   if (BTSerial.available())
    Serial.write(BTSerial.read());
 
  if (Serial.available())
    BTSerial.write(Serial.read());
}