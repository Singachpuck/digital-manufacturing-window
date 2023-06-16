#ifndef DEFAULTWEATHERSERVICE_H
#define DEFAULTWEATHERSERVICE_H

#include <sstream>
#include <utility>

#include "../WeatherService.h"

class DefaultWeatherService : public WeatherService {
protected:
    std::string key;
    std::string currentMethod = "current.json";
    std::string forecastMethod = "forecast.json";

public:
    DefaultWeatherService(HttpService* httpService, std::string baseEndpoint, std::string key) :
        WeatherService(httpService, std::move(baseEndpoint)), key(std::move(key)) {}

    DeserializationError getCurrentWeather(std::string& location, Weather* w) override;
    DeserializationError getForecastWeather(std::string &location, int hour, Weather *w) override;

    ~DefaultWeatherService() override = default;
};


#endif //DEFAULTWEATHERSERVICE_H
