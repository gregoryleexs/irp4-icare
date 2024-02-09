// Additional read on https://learn.adafruit.com/adxl345-digital-accelerometer?view=all
#include "accel.h"

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
bool adxl_detect;

void setup_accel() {
  //added to remove Uno's I2C internal pull-ups activated in wire.h
  pinMode(18, INPUT);
  pinMode(19, INPUT);

  //Setup for ADXL345
  adxl_detect = accel.begin();
  if (!adxl_detect) {
    Serial.println(F("ERROR!!!... Missing ADXL345"));
  } else {
    // Set the range to whatever is appropriate for your project
    accel.setRange(ADXL345_RANGE_2_G);
    // accel.setRange(ADXL345_RANGE_16_G);
    // accel.setRange(ADXL345_RANGE_8_G);
    // accel.setRange(ADXL345_RANGE_4_G);
  }
  //Setup for ADXL345 end
}

// read on Adafruit_ADXL345_U
float readAccelerometer() {
  if (!adxl_detect) {
    return -1;
  }

  sensors_event_t event;
  accel.getEvent(&event);  // Get a new sensor event

  /* Display the results (acceleration is measured in m/s^2) */
  // Serial.print(F("X: "));
  // Serial.print(event.acceleration.x);
  // Serial.print(F("  "));
  // Serial.print(F("Y: "));
  // Serial.print(event.acceleration.y);
  // Serial.print(F("  "));
  // Serial.print(F("Z: "));
  // Serial.print(event.acceleration.z);
  // Serial.print(F("  "));
  // Serial.println(F("m/s^2 "));

  return sqrt(event.acceleration.x * event.acceleration.x + event.acceleration.y * event.acceleration.y + event.acceleration.z * event.acceleration.z);
}

bool fallDetected() {
  if (!adxl_detect)
    return false;
  return readAccelerometer() < 2;
}
