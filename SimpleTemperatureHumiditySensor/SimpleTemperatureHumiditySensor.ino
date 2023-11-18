#include "DHT.h"

const int dhtPin = 9;
float temperature;
float humidity;
DHT dht(dhtPin, DHT11);


void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(2000);

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();


  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Fail ro read sensor DHT");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C ");
    
    Serial.print("\t"); // tabulação
  
    // Imprime o valor de umidade
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t"); 
    
    Serial.println();
  }
}
