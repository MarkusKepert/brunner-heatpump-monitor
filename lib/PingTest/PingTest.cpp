#include <ESP8266Ping.h>

void PingTest(char* remote_host) {

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