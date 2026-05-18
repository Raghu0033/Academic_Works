int ldr=12;
int val=0;
int led=13;
int pir=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(pir,INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(ldr);
  int pirval=digitalRead(pir);
  Serial.println(pirval);
  if(val==1 && pirval==1){
      Serial.println("Light is on");
      digitalWrite(led,1);
    }
  else{
    digitalWrite(led,0);
    Serial.println("Light is off");

    }
  
  delay(1000);
}