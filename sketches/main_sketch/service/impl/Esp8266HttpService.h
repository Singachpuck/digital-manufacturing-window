#ifndef ESP8266HTTPSERVICE_H
#define ESP8266HTTPSERVICE_H

#include "../HttpService.h"


class Esp8266HttpService : public HttpService {
private:
    WiFiClient client;
    HTTPClient http;

public:
    Esp8266HttpService(WiFiClient&, HTTPClient&);

    std::string httpGetJson(std::string serverName) override;
};


#endif //ESP8266HTTPSERVICE_H
