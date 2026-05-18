int ldr=12;
int val=0;
int led=13;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop() {
  val=digitalRead(ldr);
  Serial.print("LDR intensity is : ");
  if(val==1){
      Serial.println(val);
      digitalWrite(led,1);
    }
  else{
    Serial.println(val);
    digitalWrite(led,0);
    }

  delay(1000);
}