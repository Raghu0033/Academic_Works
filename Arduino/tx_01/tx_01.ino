#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int array[2];
RF24 radio(9, 10);  // CE, CSN pins
int text[2];
const byte address1[6] = "2501";
// const byte address2[6] = "2502";
// const byte address3[6] = "2503"; 
// const byte address4[6] = "2504"; // Same address as sender

void setup() {
    Serial.begin(9600);
    radio.begin();
  
    radio.setPALevel(RF24_PA_HIGH);
    radio.setChannel(100);
   radio.openWritingPipe(address1); 
   radio.stopListening();
   array[0]=2501;
}

void loop() {
    array[1]=0000;
   radio.write(&array, sizeof(array));
  delay(5000);
  array[1]=array[1]+1;





  //  if (Serial.available()) {
  //       String input = Serial.readStringUntil('\n');  // Read full message
  //       input.trim();  // Remove extra spaces or newline characters

  //       if (input.length() > 0) {  
  //           input.toCharArray(text, 32);  // Convert to char array
  //           radio.write(&text, sizeof(text));  // Send message
  //           Serial.print("Message Sent: ");
  //           Serial.println(text);
  //         }
  //  }

}