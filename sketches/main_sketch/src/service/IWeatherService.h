#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include <ctime>
#include <utility>

#include "IHttpService.h"
#include "../model/Weather.h"
#include "ArduinoJson.h"


class IWeatherService {
protected:
    IHttpService* httpService;
    std::string baseEndpoint;

public:
    IWeatherService(IHttpService* httpService, std::string baseEndpoint):
            httpService(httpService), baseEndpoint(std::move(baseEndpoint)) {}

    virtual DeserializationError getCurrentWeather(std::string& location, Weather* w) = 0;
    virtual DeserializationError getForecastWeather(std::string& location, int hour, Weather* w) = 0;

    DeserializationError getForecastWeather(std::string location, Weather* w) {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        return this->getForecastWeather(location, (now->tm_hour + 1) % 24, w);
    }

    virtual ~IWeatherService() = default;
};

#endif //WEATHERSERVICE_H
