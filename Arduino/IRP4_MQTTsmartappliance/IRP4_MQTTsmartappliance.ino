#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "credentials.h"
#include "parameters.h"
#include "profile.h"


/**** Define IO settings *******/     
#define PB 22 
#define RELAY 21

/**** Global variables *****/
long timer; 
char publish_topic[maxtopiclength];
char subscribe_topic[maxtopiclength];
uint8_t relaystatecurrent;




/**** WIFI and MQTT Client Initialise ********/
WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  pinMode(PB, INPUT);
  pinMode(RELAY, OUTPUT);
  
  digitalWrite(RELAY, HIGH);                // initialise RELAY pin HIGH; relay not energised
  
  Serial.begin(9600);
  timer= millis();                          // initialise timer
  while (!Serial) delay(1);
  set_topics();  
    
  #ifdef Ubidots                            // Read 'profile.h' on #ifdef       
     setup_wifi();
     client.setServer(mqtt_server, mqtt_port);
     client.setCallback(callback);
     client.setKeepAlive(keepalive);
  #endif
}

void loop() {

 #ifdef Ubidots                             // Read 'profile.h' on #ifdef   
    if (!client.connected()) reconnect();   
    client.loop();                          // for processing callback messages ie. subscribe messages
 #endif

 if (millis() > timer){                     // non-blocking delay check timer
  
  /*** read LDR ***/
                                      

  DynamicJsonDocument doc(256);           // JSON format eg. {"obj1-label":value,"obj2-label":value,...}
  doc["dev"] = clientid;                  // first object eg. device name or id
  doc["vol"] = 0;                    // second object eg. sense variable
  
  char mqtt_message[256];
  serializeJson(doc, mqtt_message);

  #if defined(Ubidots) && defined(Publish)
    client.publish(publish_topic, mqtt_message, true);
    Serial.println("Message published ["+String(publish_topic)+"] - "+String(mqtt_message));
  #else
    Serial.println("JSON Message - "+String(mqtt_message));
  #endif
    
  timer = millis() + max(mintxinterval, 10000);   // non-blocking delay set next tx timer in ms
 }
 
 if(digitalRead(PB) == 1)
 {
  digitalWrite(RELAY, (relaystatecurrent ^ 0x01)); //toggle the relay
  relaystatecurrent ^= 0x01;
  delay(500);
 }
}

/***** Call back Method for Receiving MQTT messages and Switching output ****/
void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);                     //copy incoming payload to p
  p[length] = NULL;
  float sub_payload = atof(p);                    //convert p to float sub_payload
  Serial.println("Message arrived ["+String(topic)+"]"+sub_payload);

  /* check incoming message */
    if( strcmp(topic,subscribe_topic) == 0)
    {      //if incoming topic == subscribe_topic
     /* use of payload to define action */
      if (sub_payload == 1) digitalWrite(RELAY,(relaystatecurrent ^ 0x01));
      relaystatecurrent ^= 0x01; //toggle the relay                           
    }                          
}

/************* Connect to WiFi ***********/
void setup_wifi() {
  delay(10);
  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected\nIP address: ");
  Serial.println(WiFi.localIP());
}

/************* Connect to MQTT Broker ***********/
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientid, mqtt_username, mqtt_password)) {
      Serial.println("connected");
       #if defined(Ubidots) && defined(Subscribe)
         client.subscribe(subscribe_topic);   // subscribe the topics here
       #endif
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");   // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void set_topics(){
  sprintf(publish_topic, "/v1.6/devices/%s", clientid);
  sprintf(subscribe_topic, "/v1.6/devices/%s/%s/lv",lev2,lev3);
}
