# irp4-icare
Source code repo for NP ECE 44IRP4 project. This project is done by Gregory Lee and Mark Daniel.
## In This Repo
This repo contains the Visual Studio solution and source files for the Windows Forms. The source code folder for the iCare wearable unit and the ESP32 MQTT smart relay can be found under the 'Arduino' folder.
## Prerequisites
### Visual Studio
Make sure Visual Studio .NET desktop development package is installed, with Windows Forms development. The NuGet packages should be restored automatically when loaded (ensure you are online).
### Arduino
For the iCare wearable unit and the ESP32 MQTT smart relay's code, the following Arduino libraries are required.
- PubSubClient (to allow the ESP32 to publish or subscribe to a topic)
- ArduinoJSON (to send JSON codes to the backends (Node-RED or Ubidots)
- WiFiESP (for the ESP8266 on the Arduino IDE)
