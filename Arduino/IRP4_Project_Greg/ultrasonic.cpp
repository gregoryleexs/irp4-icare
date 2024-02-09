//Additional read on https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
#include "ultrasonic.h"

void setup_ultrasonic() {
  pinMode(trigPin, OUTPUT);  // HC-SR04
  pinMode(echoPin, INPUT);   // HC-SR04
}

// readUltrasonic on HC-SR04
// return value
float readUltrasonic() {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
}
