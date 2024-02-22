#include <Arduino.h>
#include <PubSubClient.h>
#include "ESP8266WiFi.h"
#include "IoManager.h"

char* Wifi = "***REMOVED***";
char* WifiPSK = "***REMOVED***";
char* ping_host = "fritz.box";
char* mqttbroker_host = "10.17.3.20";


IoManager iomanager;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);

  Serial.begin(9600);
  Serial.println();

  // Setup Wifi and MQTT Connection
  iomanager.setup(Wifi, WifiPSK, mqttbroker_host);
  
  delay(100);
}

void loop() {

  int avg = iomanager.pingCheck(ping_host, true);
  iomanager.sendTopic("/home/fritzbox_ping", String(avg));
	delay(5000);

}
