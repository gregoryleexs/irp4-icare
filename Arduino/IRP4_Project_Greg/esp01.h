#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include "parameters.h"

void setup_esp01();
void wifi_setup();
void printWifiStatus();
void readWifi();
void sendHTTP(String& header, String& msg);
