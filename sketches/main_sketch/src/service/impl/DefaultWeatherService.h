#ifndef DEFAULTWEATHERSERVICE_H
#define DEFAULTWEATHERSERVICE_H

#include <ArduinoJson.h>
#include <sstream>
#include <utility>

#include "../IWeatherService.h"

/**
 * This service provides functionality to operate with weather API.
 */
class DefaultWeatherService : public IWeatherService {
protected:
    std::string key;
    std::string currentMethod = "current.json";
    std::string forecastMethod = "forecast.json";

public:
    DefaultWeatherService(IHttpService* httpService, std::string baseEndpoint, std::string key) :
            IWeatherService(httpService, std::move(baseEndpoint)), key(std::move(key)) {}

    /**
     * Method makes API call to the weather api and updates weather object with current weather data.
     * @param w pointer to the Weather object.
     * @return
     */
    DeserializationError getCurrentWeather(Weather* w) override;

    /**
     * Method makes API call to the weather api and updates weather object with weather data for a specific hour.
     * @param hour hour of weather capture (from 0 to 23)
     * @param w pointer to the Weather object.
     * @return
     */
    DeserializationError getForecastWeather(int hour, Weather *w) override;

    /**
     * Method updates Weather object based on current time (uses either forecast weather or current weather).
     * @param w pointer to the Weather object.
     */
    void updateWeather(Weather *w) override;

    ~DefaultWeatherService() override = default;
};


#endif //DEFAULTWEATHERSERVICE_H
