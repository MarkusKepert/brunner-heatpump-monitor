// MARK: Libraries
#include <PubSubClient.h>
#include "ESP8266WiFi.h"
#include <ESP8266Ping.h>
// MARK: Modules
#include "IoManager.h"

// MARK: Variables

char* mqtt_host;
long lastMsg = 0;
char msg[50];
int value = 0;

WiFiClient espClient;
PubSubClient mqtt_client(espClient);

// MARK: Constructor
IoManager::IoManager() {
  // Initialization code, if needed
}

// MARK: LifeCycle
void IoManager::setup(char* WifiName, char* WifiPSK, char* MqttBroker) {
  WiFi.begin(WifiName, WifiPSK);
  mqtt_host = MqttBroker;

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  mqtt_client.setServer(mqtt_host, 1883);
}

void IoManager::sendTopic(String Topic, String Message)
{

  if (!mqtt_client.connected()) {
		reconnect();
	}
	mqtt_client.loop();

	snprintf (msg, 50, "Alive since %ld milliseconds", millis());
	Serial.print("Publish message: ");
	Serial.println(msg);
	mqtt_client.publish(Topic.c_str(),Message.c_str());
	delay(5);
}

int IoManager::pingCheck(char* remote_host, bool LedBlink) {

  int avgResult = -1;

  if(Ping.ping(remote_host)) {
      Serial.print("Host Online ");
      avgResult = Ping.averageTime();

      Serial.println();
      Serial.println(avgResult);
      
      if (LedBlink)
      {
        digitalWrite(2, HIGH);
        delay(100);
        digitalWrite(2, LOW);
        delay(900);
      }


    } else {
    Serial.println("Host Offline");
    
    if (LedBlink)
      {
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

    return avgResult;
}

void IoManager::reconnect() 
{
	while (!mqtt_client.connected()) {
		Serial.print("Reconnecting...");
		if (!mqtt_client.connect("ESP8266Client")) {
			Serial.print("failed, rc=");
			Serial.print(mqtt_client.state());
			Serial.println(" retrying in 5 seconds");
			delay(5000);
		}
	}

}
