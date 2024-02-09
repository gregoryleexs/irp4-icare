#include "ioboard.h"

const byte arrayDigit[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x40 };
// used for 7-segmant display. Displays 0     1    2    3    4    5    6    7    8    9     -

void setup_ioboard() {
  pinMode(latchPin, OUTPUT);             // counter board
  pinMode(dataPin, OUTPUT);              // counter board
  pinMode(clockPin, OUTPUT);             // counter board
  pinMode(led13, OUTPUT);                // counter board
  pinMode(pushbutton_S1, INPUT_PULLUP);  // counter board
  pinMode(pushbutton_S2, INPUT_PULLUP);  // counter board

  displayNumber(-1);     //initialise 7-segments displays
  displayLED(false);  //initialise LED
}

// readPushButton()
// input: pin input
// return true of enable_low button is pressed.
bool readPushButton(int x) {
  return digitalRead(x) == LOW;
}

// displayLED()
// input: status_LED. 1=light up, 0=off
void displayLED(bool status_LED) { //toggle TRUE or FALSE
  digitalWrite(led13, !status_LED);
}

// displayNumber on LED
// prints "--"" for invalid numbers
void displayNumber(int num) {
  int num1 = 10;
  int num2 = 10;

  if (num >= 0 && num <= 99) {
    num1 = num % 10;         //first digit
    num2 = floor(num / 10);  //second digit
  }

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, arrayDigit[num2]);
  shiftOut(dataPin, clockPin, MSBFIRST, arrayDigit[num1]);
  digitalWrite(latchPin, HIGH);
}
