#ifndef ESP8266HTTPSERVICE_H
#define ESP8266HTTPSERVICE_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "../IHttpService.h"

class Esp8266HttpService : public IHttpService {
private:
    WiFiClient* client;
    HTTPClient* http;

public:
    Esp8266HttpService(WiFiClient*, HTTPClient*);

    /**
     * Makes GET request to the serverName and returns it's payload.
     * @param serverName the endpoint.
     * @return
     */
    std::string httpGetJson(std::string serverName) override;
};


#endif //ESP8266HTTPSERVICE_H
