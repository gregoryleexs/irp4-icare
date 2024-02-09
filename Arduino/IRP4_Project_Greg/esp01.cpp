#include "esp01.h"

SoftwareSerial espSerial(rxPin, txPin);  // RX | TX pins for ESP-01
WiFiEspClient espClient;
int wifiStatus = WL_IDLE_STATUS;  // the Wifi radio's status

void setup_esp01() {
  espSerial.begin(9600);
  wifi_setup();
}

// wifi_setup()
// [WiFiEsp] Initializing ESP module
// [WiFiEsp] Initilization successful - 1.5.4
// Attempting to connect to WPA SSID: SSID_NAME
// [WiFiEsp] Connected to SSID_NAME
void wifi_setup() {
  WiFi.init(&espSerial);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println(F("ERROR!!!... WiFi shield not present!!!"));  //Error Messages are indicated with ERROR!!!...
    return;
  }

  // attempt to connect to WiFi network
  Serial.print(F("Attempting to connect to WPA SSID: "));
  Serial.println(SSID_NAME);
  // Connect to WPA/WPA2 network
  wifiStatus = WiFi.begin(SSID_NAME, SSID_PASS);

  if (wifiStatus != WL_CONNECTED) {
    Serial.println(F("ERROR!!!... Unable to connect to network!!"));  //Error Messages are indicated with ERROR!!!...
  } else {
    printWifiStatus();
  }
}

// printWifiStatus()
// SSID: SSID_NAME
// IP Address: 192.168.43.82
// Signal strength (RSSI):-402 dBm
void printWifiStatus() {
  // print the SSID of the network you're attached to
  Serial.print(F("SSID: "));
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print(F("IP Address: "));
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print(F("Signal strength (RSSI):"));
  Serial.print(rssi);
  Serial.println(F(" dBm"));
}

/* readWifi() - if there's incoming data from the net connection send it out the serial port */
void readWifi() {
  while (espClient.available()) {
    char c = espClient.read();
    Serial.write(c);
  }
}

/*
sendHTTP(): send http to the server.
String &header: pass by reference, so that we do not create a copy of that variable into the dynamic RAM
String &msg: pass by reference, so that we do not create a copy of that variable into the dynamic RAM
Additional read on https://www.tutorialspoint.com/differences-between-pass-by-value-and-pass-by-reference-in-cplusplus
*/
void sendHTTP(String& header, String& msg) {
  if (wifiStatus != WL_CONNECTED) {
    Serial.println(F("ERROR!!!... Unable to connect to network!!"));  //Error Messages are indicated with ERROR!!!...
    return;
  }
  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  Serial.println(F("Stopping..."));
  espClient.stop();

  // if there's a successful connection
  if (espClient.connect(HTTP_SERVER, HTTP_PORT)) {
    espClient.print(header);
    espClient.print(msg);

  } else {
    // if you couldn't make a connection
    Serial.println(F("ERROR!!!... Connection failed"));  //Error Messages are indicated with ERROR!!!...
  }
}
