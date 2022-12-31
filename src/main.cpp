#include <Arduino.h>
#include "ESP8266WiFi.h"
#include <ESP8266Ping.h>

const char* remote_host = "fritz.box";


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);

  Serial.begin(9600);
  Serial.println();

  WiFi.begin("***REMOVED***", "***REMOVED***");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  delay(100);

}


void PingTest() {

  if(Ping.ping(remote_host)) {
      Serial.print("Host Online ");
      Serial.println(Ping.averageTime());
      
      delay(1000);
      digitalWrite(2, HIGH);
      digitalWrite(2, LOW);
    } else {
    Serial.println("Host Offline");
    delay(1000);
    digitalWrite(2, LOW);
    digitalWrite(2, HIGH);
    }
}

void loop() {
    PingTest();
}
