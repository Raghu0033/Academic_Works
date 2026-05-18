#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

int relay_pin=4;
String rec_data;
int time_length=10; //sec
byte Add[]="00033";
RF24 radio(9,10);

void setup(){
  Serial.begin(9600);
  pinMode(relay_pin,OUTPUT);
  radio.begin();
  radio.openReadingPipe(0,Add);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
  digitalWrite(relay_pin, HIGH);
    
}

void loop(){
  if(radio.available()){
    radio.read(&rec_data,sizeof(rec_data));
    Serial.print("data recived :");
    Serial.print(rec_data);

  }
  else {
    Serial.println("No data is reciving from TX");
  }
  if(rec_data=="control"){
    digitalWrite(relay_pin,0);
    delay(time_length*500);
    digitalWrite(relay_pin,1);
    delay(time_length*500);
    digitalWrite(relay_pin,0);
    delay(time_length*500);
    digitalWrite(relay_pin,1);
  }
  delay(5000);


}




