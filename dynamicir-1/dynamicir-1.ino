
#include <IRremoteESP8266.h>
#include "ESP8266WiFi.h"
//#include <ESP8266mDNS.h>
#include <WiFiClient.h>
//#include <EEPROM.h>
//#include <WiFiClientSecure.h>
#include <PubSubClient.h>

/**
   WIFI CONFIG
*/
const char* ssid     = "Lacus@Vossius";
const char* password = "Voss2014";
WiFiClient ESPclient;


/**
   IRSEND CONFIG
*/
IRsend irsend(16); //an IR led is connected to GPIO pin 4 (D2)

/**
   MQTT CONFIG
*/

#define MQTT_SERVER      "m21.cloudmqtt.com"
#define MQTT_PORT        11061                  
#define MQTT_USERNAME    "neddnhct"
#define MQTT_PWD         "fzxj_5M8ss6c"

PubSubClient client(ESPclient);


void setup()
{
  irsend.begin();

  Serial.begin(115200);
  delay(10);





  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");



  // Print the IP address
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.println("/");


setup_wifi();
  client.setServer(MQTT_SERVER, MQTT_PORT);


}

uint32_t x=0;

void loop() {



}

bool doDenon(unsigned int rawData1[], unsigned int rawData2[], int size1, int size2) {
  Serial.println("do denon...");
  //  Serial.println(rawData1);
  Serial.println(size1);
  Serial.println(size2);

  for (int i = 0; i < 2; i++) {
    //    Serial.println(sizeof(rawData1).toStr());
    irsend.sendRaw(rawData1, size1, 38);
    delay(75);
    Serial.println("2");
    irsend.sendRaw(rawData2, size2, 38);
    delay(64);
  }


  return true;
}



