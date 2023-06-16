#include "Esp8266HttpService.h"

Esp8266HttpService::Esp8266HttpService(WiFiClient& client, HTTPClient& http): client(client), http(http) {}

std::string Esp8266HttpService::httpGetJson(std::string serverName) {
    http.begin(client, serverName);
    http.addHeader("Accept", "application/json");

    int httpResponseCode = http.GET();

    String payload = "{}";

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    } 
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }

    http.end();

    return payload;
}