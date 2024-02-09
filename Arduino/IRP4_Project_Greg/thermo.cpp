// Additional read on https://learn.adafruit.com/using-melexis-mlx90614-non-contact-sensors?view=all
#include "thermo.h"

#define mlx_offset 4  //offset for MLX90614 as we do not have the lens for MLX90614

Adafruit_MLX90614 mlx = Adafruit_MLX90614();  // MLX90614
bool mlx_detect;                              // sensors detected

void setup_thermo() {
  //added to remove Uno's I2C internal pull-ups activated in wire.h
  pinMode(18, INPUT);
  pinMode(19, INPUT);

  mlx_detect = mlx.begin();
  if (!mlx_detect) {
    Serial.println(F("ERROR!!!... Missing MLX90614"));
  }
}

// readThermometer on Adafruit_MLX90614
// return value
// return -1 on error
double readThermometer(void) {
  if (!mlx_detect)
    return -1;
  return mlx.readObjectTempC() + mlx_offset;
}
