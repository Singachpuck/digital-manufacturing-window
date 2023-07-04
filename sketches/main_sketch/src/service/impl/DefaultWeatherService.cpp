#include "DefaultWeatherService.h"

DeserializationError DefaultWeatherService::getCurrentWeather(Weather* w) {
    std::ostringstream oss;
    oss << baseEndpoint << "/" << currentMethod << "?q=" << w->location << "&key=" << key;
    std::string endpoint = oss.str();
    std::string payload = httpService->httpGetJson(endpoint);

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

DeserializationError DefaultWeatherService::getForecastWeather(int hour, Weather *w) {
    std::ostringstream oss;
    oss << baseEndpoint << "/" << forecastMethod << "?q=" << w->location << "&key=" << key << "&hour=" << hour;
    std::string endpoint = oss.str();

    std::string payload = httpService->httpGetJson(endpoint);

    const size_t defaultPayloadCap = payload.size() * 4;
    DynamicJsonDocument doc(defaultPayloadCap);

    DeserializationError err = deserializeJson(doc, payload);

    if (!err) {
        w->precipitation = doc["forecast"]["forecastday"][0]["hour"][0]["precip_in"].as<float>();
        w->temperature = doc["forecast"]["forecastday"][0]["hour"][0]["temp_c"].as<float>();
        w->windKpH = doc["forecast"]["forecastday"][0]["hour"][0]["wind_kph"].as<float>();
    }

    return err;
}

void DefaultWeatherService::updateWeather(Weather *w) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    if (now->tm_min < 30) {
      this->getCurrentWeather(w);
    } else {
      IWeatherService::getForecastWeather(w);
    }
}
