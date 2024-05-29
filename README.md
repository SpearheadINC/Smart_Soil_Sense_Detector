# Smart_Soil_Sense_Detector
This repository contains code and instructions for a  project that uses an Arduino Uno, a DHT11 sensor, and a capacitive soil moisture sensor v1.2 to measure environmental data such as temperature, humidity, and soil moisture.

This project uses the soil moisture sensor to monitor the soil moisture level and the DHT11 sensor to monitor the ambient temperature and humidity. When the soil moisture level drops below a certain threshold, the system can automatically water the plants.

Components:
•	Capacitive Soil Moisture Sensor v1.2
•	Arduino Uno
•	DHT11 Temperature and Humidity Sensor
•	Jumper Wires
•	Cable
•	LCD display and 12C Module
•	
Capacitive_Soil_Moisture_Sensor_SKU_SEN0193-DFRobot 459
This Arduino Analog capacitive soil Moisture Sensor measures soil moisture levels by capacitive sensing, rather than resistive sensing like other types of moisture sensor. It is made of a corrosion-resistant material giving it a long service.

How to calibrate the soil moisture sensor
```
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() {
  int val;
  val = analogRead(0); //connect sensor to Analog 0
  Serial.println(val); //print the value to serial port
  delay(100);
}
```
Hardware setup
Steps:		
1.	Connect the Soil Moisture Sensor:
•	VCC to Vin on Arduino. This is the red wire.
•	GND to GND on Arduino. This is the black wire.
•	AOUT to an analog input pin (e.g., A2) on Arduino.This is the yellow wire.


2.	Connect the DHT11 Sensor:
•	VCC to 5V on Arduino
•	GND to GND on Arduino
•	Data to a digital input pin (e.g., D2) on Arduino





Software setup
**Install Arduino IDE:**
   - Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).

2. **Install Required Libraries:**
   - Open the Arduino IDE.
   - Go to `Sketch` -> `Include Library` -> `Manage Libraries`.
   - Search for and install the `DHT sensor library` by Adafruit.
   - Also, ensure the `Adafruit Unified Sensor` library is installed.

3. **Load the Code:**
   - Create a new sketch in the Arduino IDE.
   - Copy and paste the following code into the sketch:

cpp code.
```
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
```
# Explanation

- **DHT11 Sensor**: Reads temperature and humidity data.
- **Capacitive Soil Moisture Sensor**: Reads soil moisture levels.
- **Arduino Code**: Reads data from both sensors and prints the values to the Serial Monitor every 2 seconds.

# Upload the Code

1. Connect your Arduino Uno to your computer using the USB cable.
2. Select the appropriate board and port from the Tools menu.
3. Click on the Upload button to upload the code to your Arduino Uno.

# Code Explanation

## Libraries Included

- **dht.h**: Library to interface with the DHT11 sensor.

## Pin Definitions

- `#define DHT11_PIN 2`: Sets digital pin 2 for the DHT11 sensor.
- `int soilMoisturePin = A0`: Sets analog pin A0 for the soil moisture sensor.

## Setup Function

- Initializes the serial communication at a baud rate of 9600.
- Prints an initial message to the serial monitor.

## Loop Function

- Reads data from the DHT11 sensor and prints temperature and humidity values to the serial monitor.
- Reads the soil moisture level from the soil moisture sensor and prints the value to the serial monitor.
- Waits for 2 seconds before repeating the loop.

# Troubleshooting

## DHT11 Sensor Reading Issues

- Ensure the connections are correct.
- Check if the sensor is faulty by trying another DHT11 sensor.

## Soil Moisture Sensor Reading Issues

- Ensure the sensor is properly inserted into the soil.
- Check for any loose connections.

## General Issues

- Ensure the Arduino is properly connected to the computer.
- Check for any error messages in the Arduino IDE and resolve them.

# Contributions

-If you have any suggestions or improvements, please create a pull request or open an issue.

# License

This project is licensed under the MIT License. See the LICENSE file for details.
