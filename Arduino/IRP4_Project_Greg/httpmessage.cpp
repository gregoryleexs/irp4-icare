#include "httpmessage.h"
/*
generateHTTPHeader()
returns http header - around 100bytes in length
take note of the additional new line ("\r\n") required at the end of HTTP Header, before HTTP Message

POST /post HTTP/1.1
Host: postman-echo.com:80
Content-Length: 103
 
{"name":"Lim B S","studentid":"S22222222A","body":34.63,"humd":61.00,"temp":24.60,"dist":2.92,"fall":0}
*/
String generateHTTPHeader(int contentLength) {
  // Serial.println(F("Generating HTTPHeader"));
  String header = F(HTTP_SERVER_ENDPOINT);
  header += F("\r\n");

  header += F("Host: ");
  header += F(HTTP_SERVER);
  header += F(":");
  header += HTTP_PORT;
  header += F("\r\n");

  header += F("Content-Length: ");
  header += contentLength;
  header += F("\r\n");

  header += F("\r\n");  //take note of the additional new line ("\r\n") required at the end of HTTP Header, before HTTP Message

  // Serial.println(header);
  return header;
}

/*
generateJSON()
***WARNING: Arduino Uno has 32kb of flash memory but only 2kb of ram
Handle String object carefully. The main disadvantage of using the String object is that it uses a lot of memory and can quickly use up the Arduinos RAM memory, which may cause Arduino to behave unexpectedly.

Note 1: use F() to save RAM where applicable.
Avoid Serial.println("Generating Json"); The complier will create a global variable in RAM to store "Generating Json".
use Serial.println(F("Generating Json")); instead. F() tells the compiler to keep a string inside of PROGMEM and not allow it to consume RAM.
Additional read on https://www.baldengineer.com/arduino-f-macro.html

Note 2: use #define togeter with F() to save RAM. e.g. #define STUDENT_NAME "Lim B S"

Note 3: Use += operator as it don't create any temporary Strings.
Don't use the + operator to concatenate Strings as it creates a full String of the all the parts before copying it to the result String
e.g. json = "\"studentid\":\"" + STUDENT_ID + "\","; creates additional 3 temporary Strings in the complier. This is bad.

Note 4: Using json += F("\"studentid\":\""); json += F(STUDENT_ID); json += F("\","); may seem like more lines of code, but the complier will automatically opitimize the executable computer program

Note 5: body is a (float). The compiler will create a temporary String and perform the float to string conversion.

//Additional read on https://www.instructables.com/Taming-Arduino-Strings-How-to-Avoid-Memory-Issues/
*/
String generateJSON(float thermometer, bool fallDetected, bool button) {
  // Serial.println(F("Generating Json"));
  String json = F("{");
  json += F("\"name\":\"");
  json += F(STUDENT_NAME);
  json += F("\",");

  json += F("\"studentid\":\"");
  json += F(STUDENT_ID);
  json += F("\",");

  json += F("\"body\":");
  json += thermometer;
  json += F(",");

  json += F("\"Button\":");
  json += button;
  json += F(",");


  json += F("\"fall\":");
  json += fallDetected;
  json += F("}");

  

  // Serial.println(json);
  return json;
}
