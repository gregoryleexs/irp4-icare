/* Set WiFi Connection through the WIFI.h library 
   for use with WiFi.begin() in setup_wifi() of ino
   see https://docs.espressif.com/projects/arduino-esp32/en/latest/api/wifi.html
*/
    #define ssid "npiot1"
    #define password "soe040401"

/* Set Ubidots Broker Connection Details 
   for use with client.connect() 
   see https://pubsubclient.knolleary.net/api
   see also https://help.ubidots.com/en/articles/570008-ubidots-mqtt-broker
*/

    #define mqtt_server "<server address>"
    #define mqtt_username "<API token>"   //ubidots token
    #define mqtt_password ""                                      //leave blank; ie. null   
    #define mqtt_port 1883
