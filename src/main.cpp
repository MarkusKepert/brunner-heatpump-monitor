#include <Arduino.h>
#include "ESP8266WiFi.h"
#include "PingTest.h"
#include "MessageBroker.h"

char* remote_host = "fritz.box";


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

void loop() {
    PingTest(remote_host);
}
