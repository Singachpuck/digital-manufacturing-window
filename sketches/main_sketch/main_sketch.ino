#include "src/service/impl/Esp8266WifiService.h"

DefaultWifiService wifiService;

bool connected = false;

void setup() {
  Serial.begin(9600);
  delay(100);
  connected = wifiService.connectToWiFi(50) == WL_CONNECTED;
}

void loop() {
  
}
