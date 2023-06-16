#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include "HttpService.h"
#include "model/Weather.h"
#include "ArduinoJson.h"


class WeatherService {
protected:
    HttpService& httpService;
    std::string baseEndpoint;

public:
    WeatherService(HttpService& httpService, std::string baseEndpoint):
            httpService(httpService), baseEndpoint(baseEndpoint) {}

    virtual DeserializationError getCurrentWeather(std::string location, Weather* w) = 0;
};

#endif //WEATHERSERVICE_H
