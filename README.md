# irp4-icare
Source code repo for NP ECE 44IRP4 project. This project is done by Gregory Lee and Mark Daniel from PA11.
## In This Repo
This repo contains the Visual Studio solution and source files for the Windows Forms. The WinForms app package folder 'Publish' is found under 'Thermometer_Monitoring" The source code folder for the iCare wearable unit and the ESP32 MQTT smart relay can be found under the 'Arduino' folder. The sample Node-RED flow file for this project can be found under the 'node' folder. Additionally, a PDF of the wearable unit's schematic can be found under the 'SchematicPDF' folder.
## Prerequisites
### Visual Studio
Make sure Visual Studio .NET desktop development package is installed, with Windows Forms development. The NuGet packages should be restored automatically when loaded (ensure you are online).
### Arduino
For the iCare wearable unit and the ESP32 MQTT smart relay's code, the following Arduino libraries are required.
- PubSubClient (to allow the ESP32 to publish or subscribe to a topic)
- ArduinoJSON (to send JSON codes to the backends (Node-RED or Ubidots)
- WiFiESP (for the ESP8266 on the Arduino IDE)
- Adafruit MLX90614 library (infrared temperature sensor)
- Adafruit ADXL345 Accelerometer library
- Adafruit DHT11 sensor library
### Node-RED
The following nodes need to be installed:
- MySQL nodes
- sqlstring nodes
- Ubidots nodes
