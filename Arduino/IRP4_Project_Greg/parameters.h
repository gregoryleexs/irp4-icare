#include <Arduino.h>

//define hardware pins
#define rxPin 2           // ESP-01
#define txPin 3           // ESP-01
#define echoPin 4         // HC-SR04
#define trigPin 5         // HC-SR04
#define buzzer 8          //General
#define led13 13          // counter board
#define clockPin 12       // counter board
#define dataPin 11        // counter board
#define latchPin 10       // counter board
#define pushbutton_S1 9   // counter board
#define pushbutton_S2 A0  // counter board

//Student information
#define STUDENT_NAME "greg"
#define STUDENT_ID "10239908G"
#define CLASS_ID "PA11"
#define GROUP_ID "Group 1"

//Network and gateway information
#define SSID_NAME "npiot1"                          // your network SSID (name)
#define SSID_PASS "soe040401"                       // your network password
#define HTTP_SERVER "192.168.68.184"              // your http server URL;
#define HTTP_PORT 1880                                // your http server port;
#define HTTP_SERVER_ENDPOINT "POST /post1 HTTP/1.1"  // your http server endpoint;
