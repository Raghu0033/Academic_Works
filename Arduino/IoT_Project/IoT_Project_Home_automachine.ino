#include <DHT.h>
int DHTPIN=2 ;    
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
int water_sprinkle=9;
int System=10;
int light=11;
int exhauster=12;

int buzz=8;
int flame=5;
int pir1=6;
int pir2=7;
int r;
int person=0;
int flame_state;
int PIR1;
int PIR2;


 void disp(){
  Serial.println(" -- Enter Number --");
  Serial.println("===== MENU =====");
  Serial.println("0. For Menu ");
  Serial.println("1. For Temperature ");
  Serial.println("2. To OFF Light");
  Serial.println("3. To ON Light");
  Serial.println("4. To OFF exhauster");
  Serial.println("5. To ON exhauster");
  Serial.println("6. To OFF SYSTEMS");
  Serial.println("7. To ON SYSTEMS");
}
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(light,OUTPUT);
  pinMode(exhauster,OUTPUT);
  pinMode(System,OUTPUT);
  pinMode(water_sprinkle,OUTPUT);
  pinMode(buzz,OUTPUT);

  pinMode(flame,INPUT);
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);

  digitalWrite(light,1);
  digitalWrite(exhauster,1);
  digitalWrite(water_sprinkle,1);
  digitalWrite(System,1);
  digitalWrite(buzz,1);
  disp();
  r=0;

 } 

void loop() {
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  flame_state=digitalRead(flame);
  PIR1=digitalRead(pir1);
  PIR2=digitalRead(pir2);
  //Serial.println(PIR1);
  //Serial.println(PIR2);
    if (Serial.available()){
     char i=Serial.read();
    if (i=='0'){
     disp();
    }
    if (i=='1'){

      if (isnan(humidity) || isnan(temperature)) {
          Serial.println("Failed to read from DHT sensor!");
        }
          Serial.print(" %  Humidity: ");
          Serial.println(humidity);
          Serial.print(" %  Temperature: ");
          Serial.print(temperature);
          Serial.println(" C");
          float i=dht.convertCtoF(temperature);
          Serial.print(" %  Temperature (in farenheit): ");
          Serial.print(i);
          Serial.println(" F");
        }
      if(i=='2'){
        digitalWrite(light,HIGH);
      }
      if(i=='3'){
        digitalWrite(light,LOW);
      }
      if(i=='4'){
        digitalWrite(exhauster,HIGH);
      }
      if(i=='5'){
        digitalWrite(exhauster,LOW);
      }
      if(i=='6'){
      digitalWrite(System,1);

      }
      if(i=='7'){
        digitalWrite(System,0);
      }
      delay(1500);
      Serial.println();

      return;
  }
  
  if (flame_state==0){
  digitalWrite(light,1);
  digitalWrite(exhauster,1);
  digitalWrite(water_sprinkle,0);
  digitalWrite(System,1);
  digitalWrite(buzz,0);
  Serial.println("ALERT ! Fire in Room");
  delay(3000);
  }
  else{
  digitalWrite(water_sprinkle,1);
  digitalWrite(buzz,1);
  
  if(r==3 && PIR2==1 ){
    person=person+1;
  }
  else if(r==4 && PIR1==1 ){
    person=person-1;
  }
  else if(PIR1==1){
    r=3;
    delay(1500);
          Serial.println();
    return;
  }
  else if(PIR2==2){
    r=4;
    delay(1500);
          Serial.println();
    return;

  }

  if(person>0){
  digitalWrite(light,0);
  digitalWrite(exhauster,0);
  digitalWrite(water_sprinkle,1);
  digitalWrite(System,0);
  digitalWrite(buzz,1);
  }
  else if(person==0){
  digitalWrite(light,1);
  digitalWrite(exhauster,1);
  digitalWrite(water_sprinkle,1);
  digitalWrite(System,1);
  digitalWrite(buzz,1);

  }
  

  }
      Serial.println();

  delay(2500);
}