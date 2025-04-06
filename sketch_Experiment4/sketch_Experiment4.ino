#include <Arduino_APDS9960.h> // Library for APDS9960 sensor

// Reading Ambient Light and Proximity
void setup() {
  Serial.begin(9600);
  while (!Serial);
  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor!");
    while (1);
  }
}

void loop() {
  if (APDS.proximityAvailable()) {
    int proximity = APDS.readProximity();
    Serial.print("Proximity: ");
    Serial.println(proximity);
  }

  // Check if color data is available
  if (APDS.colorAvailable()) {
    int r, g, b, ambient;
    APDS.readColor(r, g, b, ambient);
    Serial.print("Color - R: ");
    Serial.print(r);
    Serial.print(", G: ");
    Serial.print(g);
    Serial.print(", B: ");
    Serial.print(b);
    Serial.print(", Ambient: ");
    Serial.println(ambient);
  }

  delay(500);
}
