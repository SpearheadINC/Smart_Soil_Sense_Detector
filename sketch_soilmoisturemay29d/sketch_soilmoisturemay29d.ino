#include <DHT.h>

#define DHTPIN 2      // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

const int soilMoisturePin = A0; // Pin connected to the soil moisture sensor

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read soil moisture value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Read temperature and humidity from DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the values to the Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  delay(2000); // Wait for 2 seconds before the next reading
}
