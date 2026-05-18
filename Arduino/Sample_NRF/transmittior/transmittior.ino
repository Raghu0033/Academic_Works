#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN
const byte address[] = "00001";  // Unique address

void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.setPALevel(RF24_PA_LOW);  // Set low power level
    radio.openWritingPipe(address);
    radio.stopListening();
}

void loop() {
    int dataToSend = 12345;  // Example integer value
    uint8_t payload[sizeof(dataToSend)];
    memcpy(payload, &dataToSend, sizeof(dataToSend));  // Convert int to byte array

    Serial.print("Sending: ");
    Serial.println(dataToSend);

    bool success = radio.write(&payload, sizeof(payload));  
    if (success) Serial.println("Sent successfully!");
    else Serial.println("Send failed!");

    delay(1000);
}