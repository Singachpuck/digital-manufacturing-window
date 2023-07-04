#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include <ctime>
#include <utility>

#include "IHttpService.h"
#include "../model/Weather.h"

/**
 * Basic interface for weather service.
 */
class IWeatherService {
protected:
    IHttpService* httpService;
    std::string baseEndpoint;

public:
    IWeatherService(IHttpService* httpService, std::string baseEndpoint):
            httpService(httpService), baseEndpoint(std::move(baseEndpoint)) {}

    virtual DeserializationError getCurrentWeather(Weather* w) = 0;
    virtual DeserializationError getForecastWeather(int hour, Weather* w) = 0;

    DeserializationError getForecastWeather(Weather* w) {
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        return this->getForecastWeather((now->tm_hour + 1) % 24, w);
    }

    virtual void updateWeather(Weather *w) = 0;

    virtual ~IWeatherService() = default;
};

#endif //WEATHERSERVICE_H
