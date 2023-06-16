#ifndef DEFAULTWEATHERSERVICE_H
#define DEFAULTWEATHERSERVICE_H

#include <sstream>

#include "../WeatherService.h"

class DefaultWeatherService : public WeatherService {
protected:
    std::string key;
    std::string currentMethod = "current.json";
    std::string forecastMethod = "forecast.json";

public:
    DefaultWeatherService(HttpService &httpService, std::string baseEndpoint, std::string key) :
        WeatherService(httpService, baseEndpoint), key(key) {}

    DeserializationError getCurrentWeather(std::string location, Weather* w) override;
};


#endif //DEFAULTWEATHERSERVICE_H
