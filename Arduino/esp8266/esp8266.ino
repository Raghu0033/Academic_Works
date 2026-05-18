
int led=5, led2=10;
int i=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  digitalWrite(led,LOW);
  digitalWrite(led2,LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:
 if((i%2)){
  digitalWrite(led,1);
  digitalWrite(led2,LOW);
  
 }
 else{
  digitalWrite(led,LOW);
  digitalWrite(led2,1);
  
 }  
i++;
delay(2000);
}
