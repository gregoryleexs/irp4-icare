#include "gameMode.h"
#include "ioboard.h"
#include "buzzer.h"

#define gameDelay 500

const byte patSeq[]  = { 0x3, 0x06, 0x0c, 0x18, 0x30, 0x21};
// used for 7-segmant display. Displays 0     1    2    3    4    5    6    7    8    9     -
const byte arrayDigit[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x40 };
// used for 7-segmant display. Displays 0     1    2    3    4    5    6    7    8    9     -

int buttonState;
int x = 0;
int y = 3 ; //random(9)
int z = 0;
uint16_t gtime = millis();
uint16_t gameLt;

void gameMode()
{                       
  if(risingPB(9))
  {
   x++;
   x = x%10;
  }

  GuessStart(z, x);
  gtime = millis();
  if ( gtime >= gameLt ){
    gameLt = gtime + gameDelay;
    z++;
    z = z%6;
  }

  if(risingPB(A0))
  {
    if (x == y)
    {
      int t = 10*y + x;
      displayNumber(t);
      beep(50);
      Serial.println(F("Correct!"));
      Serial.print(F("The number was "));
      Serial.print(y);
      Serial.println();
      Serial.println();
      delay(3000);
    }
    else
    {
      int t = 10*y + x;
      displayNumber(t);
      beepShort(6);
      Serial.println(F("Incorrect!"));
      Serial.print(F("The number was "));
      Serial.print(y);
      Serial.println();
      Serial.println();
      delay(3000);
    }
    //y = random(9);
  }
}


bool risingPB(int Pin)
{
  buttonState = digitalRead(Pin);
  delay(50);
  if (buttonState != digitalRead(Pin)) 
  {
    if (buttonState == HIGH)
    {
      return 1;
    } 
    delay(50);
  }
  return 0;
}

void GuessStart(int patNo, int num1) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, patSeq[patNo]);
  shiftOut(dataPin, clockPin, MSBFIRST, arrayDigit[num1]);
  digitalWrite(latchPin, HIGH);
}
