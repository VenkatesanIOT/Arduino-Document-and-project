/*
 * TamilZorous info tech 
*/
#include "DHT.h"
#define DHT11PIN 5 //D1 input
#define DHT11TYPE DHT11
DHT dht11(DHT11PIN, DHT11TYPE);
void setupAP(void);
void setup() {
  Serial.begin(115200);                                  //Serial connection
  dht11.begin();
}
void loop() {
  float h11 = dht11.readHumidity();
  float t11 = dht11.readTemperature();
if (isnan(t11) || isnan(h11)) {
    Serial.println("Failed to read from DHT #1");
  } else {
    Serial.print("Humidity 11: "); 
    Serial.println(h11);
    //Serial.print(" %\t");
    Serial.print("Temperature 11: "); 
    Serial.println(t11);
    Serial.println(" *C");
  }
  delay(1000);
}
