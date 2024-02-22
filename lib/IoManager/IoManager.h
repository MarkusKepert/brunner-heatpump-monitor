#ifndef IO_MANAGER_H
#define IO_MANAGER_H
// MARK: Libraries
#include <Arduino.h>
// MARK: Class / Functions / Variables
class IoManager {
public:
  // MARK: Lifecycle
  void setup(char* WifiName, char* WifiPSK, char* MqttBroker);
  void sendTopic(String Topic, String Message);
  int pingCheck(char* remote_host, bool LedBlink);
  // public constructor to prevent direct instantiation
  IoManager();
private:
  // MARK: Variables
  // Debuging Identifier
  String debugIdentifier = "[IO MANAGER] | ";
  void reconnect();
};



#endif
