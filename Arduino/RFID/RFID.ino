//Viral Science
//RFID
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
String stored[5] = {" 73 B9 D2 2E" , " C3 6B D5 F8" , " 13 F8 F6 C4" ," E3 28 EB FA", " 33 29 50 F6"};
//----------------------------------------------------------------------
//----------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();
}
//----------------------------------------------------------------------
void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;

  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();

  if (content == stored[0] ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access to CSE");
    Serial.println();
    delay(500);
    return;
  }
   if ( content== stored[1]) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access to ECE");
    Serial.println();
    delay(500);
    
    return;
  }
  if (content == stored[2] ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access to EEE");
    Serial.println();
    delay(500);

    return;
  }
  if (content == stored[4] ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access MECH");
    Serial.println();
    delay(500);
    return;
  }
  if (content == stored[3] ) {
  Serial.println("Authorized access MMe");
  Serial.println();
  delay(500);
  }
  else{
      Serial.println("unAuthorized access");
  Serial.println();
  delay(500);
  }
  return;
}