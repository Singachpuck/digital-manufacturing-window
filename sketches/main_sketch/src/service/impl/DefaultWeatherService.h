#ifndef DEFAULTWEATHERSERVICE_H
#define DEFAULTWEATHERSERVICE_H

#include <sstream>
#include <utility>

#include "../IWeatherService.h"

class DefaultWeatherService : public IWeatherService {
protected:
    std::string key;
    std::string currentMethod = "current.json";
    std::string forecastMethod = "forecast.json";

public:
    DefaultWeatherService(IHttpService* httpService, std::string baseEndpoint, std::string key) :
            IWeatherService(httpService, std::move(baseEndpoint)), key(std::move(key)) {}

    DeserializationError getCurrentWeather(std::string& location, Weather* w) override;
    DeserializationError getForecastWeather(std::string &location, int hour, Weather *w) override;

    ~DefaultWeatherService() override = default;
};


#endif //DEFAULTWEATHERSERVICE_H
