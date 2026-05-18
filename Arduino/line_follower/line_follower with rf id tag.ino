#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
String stored[5] = {" 73 B9 D2 2E" , " C3 6B D5 F8" , " 13 F8 F6 C4" ," E3 28 EB FA", " 33 29 50 F6"};
const int enA = 5;
const int enB = 6;
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 7;
 int M1_Speed = 180; 
 int M2_Speed = 180;  
 int LeftRotationSpeed = 250;   
 int RightRotationSpeed = 250; 

 void setup() {

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  Serial.begin(9600); 
  SPI.begin();    
  mfrc522.PCD_Init(); 
  Serial.println("Put your card to the reader...");
  Serial.println();
  disp();
}

void loop() {

  
   if (Serial.available()){
     char i=Serial.read();
    if (i=='0'){
     disp();
    }
    if (i=='1'){
        forward();
    }
     else if(i=='2'){
        left();       
      }
    else  if(i=='3'){
        right();
      }
     else if(i=='4'){
        backward();
      }
    else  if(i=='5'){
        Stop();
      }
   }

 if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    //Serial.print("2");
    return;

  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    //Serial.print("3");
    return;
  }
  //Show UID on serial monitor
  Stop();
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
  return;
  }
  else{
      Serial.println("unAuthorized access");
  Serial.println();
  delay(500);
  }
  return;
}



void forward() {
     digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
    analogWrite(enA, M1_Speed);
    analogWrite(enB, M2_Speed);
}

void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, M1_Speed);
  analogWrite(enB, M2_Speed);
}

void right()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            analogWrite(enA, LeftRotationSpeed);
            analogWrite(enB, RightRotationSpeed);
}

void left()
{
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
            analogWrite(enA, LeftRotationSpeed);
            analogWrite(enB, RightRotationSpeed);
}                                                                                                             
void Stop()
{
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, LOW);
}
void disp(){
  Serial.println(" -- Enter Number --");
  Serial.println("===== MENU =====");
  Serial.println("0. For Menu ");
  Serial.println("1. Forward ");
  Serial.println("2. left");
  Serial.println("3. right");
  Serial.println("4. backward");
}
