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
int flame_state;


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

  digitalWrite(light,1);
  digitalWrite(exhauster,1);
  digitalWrite(water_sprinkle,1);
  digitalWrite(System,1);
  digitalWrite(buzz,1);
  disp();
  
 } 

void loop() {
  
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  flame_state=digitalRead(flame);
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
  }
     
  delay(2500);
}