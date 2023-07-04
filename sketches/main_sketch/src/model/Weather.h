#ifndef WEATHER_H
#define WEATHER_H

#include <utility>

/**
 * Represents weather structure.
 * Contains the following fields:
 * - location: current location of the weather.
 * - temperature: temperature value (Celsius value)
 * - windKpH: wind speed (kilometers per hour)
 * - precipitation: level of precipitation (millimeters)
 */
class Weather {
public:
    std::string location;
    float temperature = 0;
    float windKpH = 0;
    float precipitation = 0;

    Weather(std::string location) : location(std::move(location)) {};

    Weather(std::string location, float temperature, float windKpH, float precipitation) : location(std::move(location)),
                                                                                                  temperature(
                                                                                                          temperature),
                                                                                                  windKpH(windKpH),
                                                                                                  precipitation(
                                                                                                          precipitation) {}
};

#endif //WEATHER_H