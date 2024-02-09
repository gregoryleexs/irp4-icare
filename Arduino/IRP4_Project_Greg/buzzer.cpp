#include "buzzer.h"

void setup_buzzer() {
  pinMode(buzzer, OUTPUT);  // General
  pinMode(12, OUTPUT); //vibration motor
  beep();                   //beep once
}

// beep on buzzer
void beep(int x) {
  int i = 0;
  while (i < x) {
    beep();
    i++;
  }
}

void beepShort(int y) {
  int i = 0;
  while (i < y) {
    beepShort();
    i++;
  }
}

void beep() {
  tone(buzzer, 2000);
  digitalWrite(12, HIGH);
  delay(300);
  noTone(buzzer);
  digitalWrite(12, LOW);
  delay(300);
}

void beepShort() {
  //digitalWrite(buzzer, HIGH);
  tone(buzzer, 1000);
  digitalWrite(12, HIGH);
  delay(50);
  noTone(buzzer);
  digitalWrite(12, LOW);
  delay(50);
}
