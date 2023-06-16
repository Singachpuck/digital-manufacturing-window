#ifndef WEATHER_H
#define WEATHER_H

class Weather {
public:
    float temperature = 0;
    float windKpH = 0;
    float precipitation = 0;

    Weather() = default;

    Weather(float temperature, float windKpH, float precipitation) :
        temperature(temperature), windKpH(windKpH), precipitation(precipitation) {}
};

#endif //WEATHER_H