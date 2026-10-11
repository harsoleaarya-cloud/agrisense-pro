

#include <DHT.h>

// ---- Pins: change these to match your wiring ----
#define DHT_PIN   2        // DHT11 data pin
#define DHT_TYPE  DHT11
#define SOIL_PIN  A0       // soil moisture sensor analog output

// ---- Soil sensor calibration ----
// Read the raw value with the probe in dry air (SOIL_DRY)
// and fully submerged in water (SOIL_WET), then put them here.
const int SOIL_DRY = 1023;
const int SOIL_WET = 300;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();   // Celsius
  float humidity    = dht.readHumidity();      // %
  int   raw         = analogRead(SOIL_PIN);

  // Convert raw reading to 0-100 %
  int moisture = map(raw, SOIL_DRY, SOIL_WET, 0, 100);
  moisture = constrain(moisture, 0, 100);

  // Skip the reading if the DHT11 failed
  if (isnan(temperature) || isnan(humidity)) {
    delay(2000);
    return;
  }

  Serial.print(temperature, 0);
  Serial.print(",");
  Serial.print(humidity, 0);
  Serial.print(",");
  Serial.println(moisture);

  delay(2000);   // DHT11 needs at least ~1 s between reads
}
