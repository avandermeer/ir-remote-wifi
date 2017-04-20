
#include <IRremoteESP8266.h>
#include "ESP8266WiFi.h"
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
#include <EEPROM.h>
#include <WiFiClientSecure.h>

const char* ssid     = "Lacus@Vossius";
const char* password = "Voss2014";


WiFiServer server(80);

IRsend irsend(16); //an IR led is connected to GPIO pin 4 (D2)

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

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request

  if (request.indexOf("/POWER") != -1) {
    //POWER:
    unsigned int  rawData1[31] = {400, 700, 400, 700, 400, 1750, 400, 1750, 400, 700, 400, 1750, 400, 1750, 400, 1750, 400, 1750, 400, 700, 400, 1750, 400, 700, 400, 1750, 400, 1750, 400, 1750, 400}; // UNKNOWN 1BD7
    unsigned int  rawData2[10] = {750, 350, 1800, 350, 750, 350, 750, 350, 750, 350 };
Serial.println((sizeof(rawData1)/sizeof(unsigned int)));
    doDenon(rawData1, rawData2, sizeof(rawData1)/sizeof(unsigned int), sizeof(rawData2)/sizeof(unsigned int));
  }
  if (request.indexOf("/VOLUP") != -1) {
    //VOL UP:
    unsigned int  rawData1[31] = {350, 750, 350, 750, 350, 1800, 350, 1800, 350, 750, 350, 1800, 350, 750, 350, 1800, 350, 1800, 350, 750, 350, 750, 350, 1800, 350, 750, 350, 750, 350, 750, 350}; // UNKNOWN 1AC8
    unsigned int  rawData2[17] = {350, 750, 350, 750, 350, 1800, 350, 1800, 350, 750, 350, 1800, 350, 1800, 350, 1800, 350}; // UNKNOWN B9AB2517
doDenon(rawData1, rawData2, sizeof(rawData1)/sizeof(unsigned int), sizeof(rawData2)/sizeof(unsigned int));
  }

  if (request.indexOf("/VOLDOWN") != -1) {
    //VOL DOWN:
    unsigned int  rawData1[31] = {350, 750, 350, 750, 350, 1800, 350, 1800, 350, 750, 350, 750, 350, 750, 350, 1800, 350, 1800, 350, 750, 350, 750, 350, 1800, 350, 750, 350, 750, 350, 750, 350}; // UNKNOWN 18C8
    unsigned int  rawData2[19] = {350, 1800, 350, 750, 350, 750, 350, 1800, 350, 1800, 350, 750, 350, 1800, 350, 1800, 350, 1800, 350}; // UNKNOWN CBF358E
doDenon(rawData1, rawData2, sizeof(rawData1)/sizeof(unsigned int), sizeof(rawData2)/sizeof(unsigned int));

  }



  // Set ledPin according to the request
  //digitalWrite(ledPin, value);


  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("done ");


  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}

bool doDenon(unsigned int rawData1[], unsigned int rawData2[], int size1, int size2) {
  Serial.println("do denon...");
//  Serial.println(rawData1);
Serial.println(size1);
Serial.println(size2);

  for (int i = 0; i < 3; i++) {
//    Serial.println(sizeof(rawData1).toStr());
    irsend.sendRaw(rawData1, size1, 38);
    delay(75);
    Serial.println("2");
    irsend.sendRaw(rawData2, size2, 38);
    delay(64);
  }
//  for (int i = 0; i < 3; i++) {
//  unsigned int  rawData1[31] = {400, 700, 400, 700, 400, 1750, 400, 1750, 400, 700, 400, 1750, 400, 1750, 400, 1750, 400, 1750, 400, 700, 400, 1750, 400, 700, 400, 1750, 400, 1750, 400, 1750, 400}; // UNKNOWN 1BD7
//    irsend.sendRaw(rawData1, 31, 38);
//    delay(75);
//    unsigned int  rawData2[10] = {750, 350, 1800, 350, 750, 350, 750, 350, 750, 350 };
//    irsend.sendRaw(rawData2, 10, 38);
//    delay(64);
//  }

  return true;
}



