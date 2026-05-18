//int led=11;
int i=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  for(i=0;i<=255;i++){
    Serial.print(i);
    Serial.print(";");
    delay(500);
  }
  /*if(Serial.available()>0){
    int num=Serial.read();
    Serial.println(num);
    int n=map(num,0,100,0,255);
    analogWrite(led,n);
  
   for(i=255;i>=0;i--){
    analogWrite(led,i);
    delay(50);
  }*/
  }

