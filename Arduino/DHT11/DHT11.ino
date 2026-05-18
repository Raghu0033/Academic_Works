#include <DHT.h>

int DHTPIN=2 ;    // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11 sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read temperature and humidity from the sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if the sensor read was successful
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;
  }

  // Print the values to the Serial Monitor
  Serial.print(" %  Humidity: ");
  Serial.println(humidity);
  Serial.print(" %  Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  float i=dht.convertCtoF(temperature);
  Serial.print(" %  Temperature (in farenheit): ");
  Serial.print(i);
  Serial.println(" F");
  // float j=dht.convertCtoK(temperature);
  Serial.print(" %  Temperature (in Kelvin): ");
  // Serial.print(j);
  // Serial.println(" K");

  delay(1000);
}