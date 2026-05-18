#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN

const byte address1[] = "00001";  // TX1 address
const byte address2[] = "00002";  // TX2 address

void setup() {
    Serial.begin(9600);
    radio.begin();
    
    radio.openReadingPipe(1, address1);  // Pipe for TX1
    radio.openReadingPipe(2, address2);  // Pipe for TX2

    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();  // Start receiving
}

void loop() {
    if (radio.available()) {
        int receivedData;
        byte pipeNum;
        
        radio.available(&pipeNum);  // Get pipe number
        radio.read(&receivedData, sizeof(receivedData));  // Read data

        Serial.print("Received from TX");
        
        if (pipeNum == 1) {
            Serial.print("1: ");
        } else if (pipeNum == 2) {
            Serial.print("2: ");
        } else {
            Serial.print("? (Unknown Pipe): ");  // If something unexpected happens
        }
        
        Serial.println(receivedData);
    }
}