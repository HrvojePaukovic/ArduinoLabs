#include <Arduino_LSM9DS1.h> // For the magnetometer

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Monitor to open

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  float mx, my, mz;

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mx, my, mz);

    Serial.print("Magnetic Field X: ");
    Serial.print(mx);
    Serial.print(" uT, Y: ");
    Serial.print(my);
    Serial.print(" uT, Z: ");
    Serial.println(mz);
    Serial.print(" uT\n");
  }

  delay(500);
}
