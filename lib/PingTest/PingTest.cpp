#include <ESP8266Ping.h>

void PingTest(char* remote_host) {

  if(Ping.ping(remote_host)) {
      Serial.print("Host Online ");
      Serial.println(Ping.averageTime());
      
      digitalWrite(2, HIGH);
      delay(100);
      digitalWrite(2, LOW);
      delay(900);
    } else {
    Serial.println("Host Offline");
    
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(50);
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(850);
    }
}