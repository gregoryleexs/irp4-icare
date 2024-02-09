#include "DHT.h"

#include "ioboard.h"
#include "esp01.h"
#include "httpmessage.h"
#include "parameters.h"
#include "thermo.h"
#include "ultrasonic.h"
#include "buzzer.h"
#include "accel.h"
#include "gamemode.h"

#define DHTPIN 6
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int fall = 0;
int button = 0;
int tempalertCnt;
float ambTemp;
uint16_t DHTlt;
uint16_t time = millis();
int Switch = 7;

// put your setup code here, to run once:
void setup() {
  Serial.begin(9600);
  Serial.println(F("Initializing..."));

  dht.begin();
  pinMode(Switch, INPUT);
  setup_ioboard();
  setup_ultrasonic();
  setup_thermo();
  setup_esp01();
  setup_buzzer();
  setup_accel();
  displayNumber(-1);

  Serial.println(F("Setup Completed"));
}

// put your main code here, to run repeatedly:
void loop() {

  
  if(digitalRead(Switch) == HIGH)
  {
    gameMode();
  }
  else
  {
    normalMode();
  }
  
  
   readWifi();
  
}



// When the ultrasonic sensor detects the body distance is within 2cm to 3cm, the non-contact thermometer sensor will take the body temperature and value will be uploaded to a test echo server via the ESP8266-01 Wi-Fi module.
void normalMode() 
{
  float d = readUltrasonic();
  //Serial.println(readUltrasonic());
  time = millis();
  
  if ( checktime(2500) )
  {
    ambTemp = dht.readTemperature();
    Serial.println(ambTemp);
  }

  while ( ambTemp >= 34 && !readPBs() )
  {
    if ( checktime(2500))
    {
      if(tempalertCnt < 5)
      {
        Serial.println(tempalertCnt);
        beepShort(6);
        ambTemp = dht.readTemperature();
        Serial.println(F("WARNING**"));
        Serial.print(F("Ambient temperature detected is "));
        Serial.print(ambTemp);
        Serial.println();
        Serial.println(F("Please seek shelter immediately"));
        Serial.println(F("WARNING**"));
        Serial.println();
        tempalertCnt++;
      }
      else
      {
        if(tempalertCnt == 50)
        {
          tempalertCnt = 0;
        }
        tempalertCnt++;
        break;
        
      }
    }
    
  }
  
  if(fallDetected())
  {
    Serial.println (F("ALARM"));
    fall++;
    beepShort(15);
    postMessageToServer(readThermometer(), fall, 0);
  }
  if (d <= 3 && d >= 2) 
  {
    float x = readThermometer();
    if(x > 30)
    {
      for(int i = 1; i < 6; i++)
      {
        beep(1);
        displayNumber(100);
        delay(400);
        displayNumber(x);
      }
      
    }
    displayNumber(x);
    beep(1);
    postMessageToServer(x, fall, 0);
      
  }
    
    
  if(readPBs())
  {
    for(int i = 0; i < 30; i++)
    {
      if(!readPBs())
      {
        break;
      }
      delay(100);
      if(i == 29)
      {
       Serial.println("HELP NEEDED!!");
       displayLED(true);
       beepShort(30);
       postMessageToServer(readThermometer(), true, 0);
      }
    }
  }
    if((readPushButton(A0)) == 1)
    {
      button++;
      Serial.println("Triggered switch");
      postMessageToServer(readThermometer(), fall, button);
    }
    
    //delay(5000);
    
  

  
}

void timerMode()
{
  int time = 99;
  for(time; time > 0; time--)
  {
    displayNumber(time);
    delay(500);
  }
  beep(20);
  
}

bool readPBs(){
  if ( (readPushButton(9) == 1) && (readPushButton(A0) == 1) )
  {
    return 1;
  }
  return 0;
}

bool checktime (uint16_t lt ){
  time = millis();
  if ( time >= DHTlt )
  {
    DHTlt = time + lt;
    return 1;
  }
  return 0;
}

/*
postMessageToServer() - post message to server
*/
void postMessageToServer(float thermometer, bool fallDetected, bool button) {
  String msg = generateJSON(thermometer, fallDetected, button);
  String header = generateHTTPHeader(msg.length());
  Serial.print(header);
  Serial.println(msg);
  sendHTTP(header, msg);
  fall = 0; //need to reset fall to 0
  button = 0;
}
