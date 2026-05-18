#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>

RF24 radio(9, 10); 
byte pipeNo;
SoftwareSerial BTSerial(2, 3); 
unsigned long lastReceived = millis();
const int relay1Pin = 5; 
const byte address1[] = "10033"; 
const byte address2[] = "20749"; 

float dataArray[4] ;
float m2=1023;
bool moisture1Received = false;
bool moisture2Received = false;
bool tempReceived = false;
bool humidityReceived = false;


void setup() {
    Serial.begin(9600);
    BTSerial.begin(9600);
    Serial.println("Initializing NRF24L01...");
    pinMode(relay1Pin, OUTPUT); 
    digitalWrite(relay1Pin, HIGH);
    if (!radio.begin()) {
        Serial.println("NRF24L01 module not detected. Check wiring!");
        while (1);
    }
    Serial.println("NRF24L01 detected and initialized!");
    radio.openReadingPipe(0, address1); 
    radio.openReadingPipe(1, address2); 
    radio.setPALevel(RF24_PA_LOW);
    radio.startListening(); 
    Serial.println("Receiver is now listening...");
    radio.printDetails();
}

void loop() {
    // Serial.println(dataArray[1]);
    //   if((m2<400)){
    //             digitalWrite(relay1Pin,HIGH);
    //   }
    // else 
    if (BTSerial.available()) {
        Serial.println(" bt readed");
        bool relayControl = BTSerial.read();
        Serial.println(relayControl); // Read the boolean input
        if (relayControl == 1) {
            digitalWrite(relay1Pin, LOW); // Turn on relay 1
             // Turn on relay 2
        }
        else{
          digitalWrite(relay1Pin,HIGH);
        }
    }
    else {
      digitalWrite(relay1Pin,LOW);
    }

    while (radio.available(&pipeNo)) {
        if (pipeNo == 0) {
            float receivedMoisture1;
            radio.read(&receivedMoisture1, sizeof(receivedMoisture1));
            dataArray[0] = receivedMoisture1; 
            moisture1Received = true; 
            Serial.print("Moisture 1: ");
            Serial.println(receivedMoisture1);
        } else if (pipeNo == 1) {
            float receivedData[3];
            radio.read(&receivedData, sizeof(receivedData));
            dataArray[3] = receivedData[0]; 
            dataArray[2] = receivedData[1]; 
            dataArray[1] = receivedData[2]; 
             m2 = receivedData[2]; 
            humidityReceived = true; 
            tempReceived = true; 
            moisture2Received = true; 
            Serial.print("Humidity: ");
            Serial.println(receivedData[0]);
            Serial.print("Temperature: ");
            Serial.println(receivedData[1]);
            Serial.print("Moisture 2: ");
            Serial.println(receivedData[2]);
              
  }
        
        lastReceived = millis(); // Update last received time
        radio.flush_rx(); // Clear the RX buffer
    }

    // Check if all data has been received
    if (moisture1Received && moisture2Received && tempReceived && humidityReceived) {
        // Send the array via Bluetooth
        BTSerial.print("[");
        for (int i = 0; i < 4; i++) {
            BTSerial.print(dataArray[i]);
            if (i < 3) BTSerial.print(", ");
        }
        BTSerial.println("]");

        // Reset flags and array for next reception
        memset(dataArray, 0, sizeof(dataArray));
        moisture1Received = false;
        moisture2Received = false;
        tempReceived = false;
        humidityReceived = false;
    }
    // If no data is received for 5 seconds, reset
    if (millis() - lastReceived > 5000) {
        Serial.println("No data received, RX Waiting for Data...");
        radio.stopListening();
        radio.flush_rx();
        delay(5);
        radio.startListening();
        lastReceived = millis();
    }
}