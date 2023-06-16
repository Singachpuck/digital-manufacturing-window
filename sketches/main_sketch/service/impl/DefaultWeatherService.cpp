#include "DefaultWeatherService.h"

DeserializationError DefaultWeatherService::getCurrentWeather(std::string location, Weather* w) {
    std::ostringstream oss;
    oss << baseEndpoint << "/" << currentMethod << "?q=" << location << "&key=" << key;
    std::string endpoint = oss.str();
    std::string payload = httpService.httpGetJson(endpoint);

    const size_t defaultPayloadCap = payload.size() * 4;
    DynamicJsonDocument doc(defaultPayloadCap);

    DeserializationError err = deserializeJson(doc, payload);

    if (!err) {
        w->precipitation = doc["current"]["precip_in"].as<float>();
        w->temperature = doc["current"]["temp_c"].as<float>();
        w->windKpH = doc["current"]["wind_kph"].as<float>();
    }

    return err;
}