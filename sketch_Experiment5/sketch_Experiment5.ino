/* LPS22HB - Read Pressure. This example reads data from the on-board
LPS22HB sensor of the Nano 33 BLE Sense and prints the temperature and
pressure sensor value to the Serial Monitor once a second. */
#include <Arduino_LPS22HB.h>
#include <math.h> // for pow()

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (1);
  }
}

void loop() {
  float pressure = BARO.readPressure();      // in kPa
  float temperature = BARO.readTemperature();

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" kPa");
          
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Altitude calculation
  float seaLevelPressure = 101.325; // kPa
  float altitude = 44330.0 * (1.0 - pow(pressure / seaLevelPressure, 0.1903));

  Serial.print("Estimated Altitude = ");
  Serial.print(altitude);
  Serial.println(" m");

  Serial.println();
  delay(1000);
}