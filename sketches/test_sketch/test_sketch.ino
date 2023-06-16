#include <ESP8266WiFi.h>

#include "creds.h"


WiFiClient client;

void connectToWiFi() {
  const int n_retries = 50;
  Serial.println();
  Serial.print(F("Connecting to WiFi"));
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  int retries = 0;
  while ((WiFi.status() != WL_CONNECTED) && (retries < n_retries)) {
    retries++;
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F("WiFi connected!"));
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println(F("WiFi connection FAILED"));
  }
  Serial.println(F("Setup finished!"));
}


void setup() {
  Serial.begin(9600);
  delay(100);
  connectToWiFi();
}

void loop() {

}
