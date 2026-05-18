int inpin=11;
int led=13;
void setup() {
  pinMode(inpin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int re=digitalRead(inpin);
  if(re==1){
    Serial.println("Motion Detected"); 
    digitalWrite(led,HIGH); 
  }
  else{
    Serial.println("Motion Not Detected");
        digitalWrite(led,LOW); 

  }
  // put your main code here, to run repeatedly:
  delay(1500);
}
