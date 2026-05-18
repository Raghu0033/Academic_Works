#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
char text[32];
RF24 radio(9, 10);  // CE, CSN pins
const byte address[6] = "TX10B";
void setup() {
    Serial.begin(9600);
    Serial.println("Initializing NRF24L01...");

    if (!radio.begin()) {
        Serial.println("NRF24L01 module not detected. Check wiring!");
        while (1);
    }
    Serial.println("NRF24L01 detected and initialized!");
    radio.openReadingPipe(0, address);  // Use a 5-byte address
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening();  // Set as receiver

    Serial.println("Receiver is now listening...");
    radio.printDetails();  // Print NRF24L01 details for debugging
}
void loop() {
    if (radio.available()) {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.print("Received: ");
        Serial.println(text);
    }
    delay(1000);
}