#include "gtest/gtest.h"
#include "MockHttpService.h"
#include "service/impl/DefaultWeatherService.h"

using namespace ::testing;

class HttpPayloadTest : public Test {

public:
    std::string currentPayload = R"({"location":{"name":"Rennes","region":"Bretagne","country":"France","lat":48.11,"lon":-1.68,"tz_id":"Europe/Paris","localtime_epoch":1686867157,"localtime":"2023-06-16 0:12"},"current":{"last_updated_epoch":1686866400,"last_updated":"2023-06-16 00:00","temp_c":20.0,"temp_f":68.0,"is_day":0,"condition":{"text":"Clear","icon":"//cdn.weatherapi.com/weather/64x64/night/113.png","code":1000},"wind_mph":5.6,"wind_kph":9.0,"wind_degree":330,"wind_dir":"NNW","pressure_mb":1019.0,"pressure_in":30.09,"precip_mm":0.0,"precip_in":0.0,"humidity":60,"cloud":0,"feelslike_c":20.0,"feelslike_f":68.0,"vis_km":10.0,"vis_miles":6.0,"uv":1.0,"gust_mph":12.8,"gust_kph":20.5}})";
    std::string forecastPayload = R"({"location":{"name":"Paris","region":"Ile-de-France","country":"France","lat":48.87,"lon":2.33,"tz_id":"Europe/Paris","localtime_epoch":1686931435,"localtime":"2023-06-16 18:03"},"current":{"last_updated_epoch":1686931200,"last_updated":"2023-06-16 18:00","temp_c":29.0,"temp_f":84.2,"is_day":1,"condition":{"text":"Sunny","icon":"//cdn.weatherapi.com/weather/64x64/day/113.png","code":1000},"wind_mph":5.6,"wind_kph":9.0,"wind_degree":10,"wind_dir":"N","pressure_mb":1016.0,"pressure_in":30.0,"precip_mm":0.0,"precip_in":0.0,"humidity":29,"cloud":0,"feelslike_c":27.9,"feelslike_f":82.3,"vis_km":10.0,"vis_miles":6.0,"uv":7.0,"gust_mph":5.4,"gust_kph":8.6},"forecast":{"forecastday":[{"date":"2023-06-16","date_epoch":1686873600,"day":{"maxtemp_c":32.3,"maxtemp_f":90.1,"mintemp_c":16.4,"mintemp_f":61.5,"avgtemp_c":23.9,"avgtemp_f":75.0,"maxwind_mph":4.9,"maxwind_kph":7.9,"totalprecip_mm":0.0,"totalprecip_in":0.0,"totalsnow_cm":0.0,"avgvis_km":10.0,"avgvis_miles":6.0,"avghumidity":45.0,"daily_will_it_rain":0,"daily_chance_of_rain":0,"daily_will_it_snow":0,"daily_chance_of_snow":0,"condition":{"text":"Sunny","icon":"//cdn.weatherapi.com/weather/64x64/day/113.png","code":1000},"uv":6.0},"astro":{"sunrise":"05:47 AM","sunset":"09:56 PM","moonrise":"04:12 AM","moonset":"08:45 PM","moon_phase":"Waning Crescent","moon_illumination":"5","is_moon_up":0,"is_sun_up":0},"hour":[{"time_epoch":1686934800,"time":"2023-06-16 19:00","temp_c":26.3,"temp_f":79.3,"is_day":1,"condition":{"text":"Partly cloudy","icon":"//cdn.weatherapi.com/weather/64x64/day/116.png","code":1003},"wind_mph":4.0,"wind_kph":6.5,"wind_degree":34,"wind_dir":"NE","pressure_mb":1016.0,"pressure_in":30.01,"precip_mm":0.0,"precip_in":0.0,"humidity":35,"cloud":46,"feelslike_c":25.9,"feelslike_f":78.6,"windchill_c":26.3,"windchill_f":79.3,"heatindex_c":25.9,"heatindex_f":78.6,"dewpoint_c":9.5,"dewpoint_f":49.1,"will_it_rain":0,"chance_of_rain":0,"will_it_snow":0,"chance_of_snow":0,"vis_km":10.0,"vis_miles":6.0,"gust_mph":5.6,"gust_kph":9.0,"uv":7.0}]}]}})";

    MockHttpService* http = nullptr;
    WeatherService* weatherService = nullptr;

    ~HttpPayloadTest() override {
        delete http;
        delete weatherService;
    }

protected:
    void SetUp() override {
        http = new MockHttpService();
        ON_CALL(*http, httpGetJson(_)).WillByDefault(Throw(std::exception()));
        ON_CALL(*http, httpGetJson(HasSubstr("current"))).WillByDefault(Return(currentPayload));
        ON_CALL(*http, httpGetJson(HasSubstr("forecast"))).WillByDefault(Return(forecastPayload));

        std::string baseEndpoint = "http://api.weatherapi.com/v1";
        std::string key = "12345";
        weatherService = new DefaultWeatherService(http, baseEndpoint, key);
    }
};

TEST_F(HttpPayloadTest, PayloadParseTest) {
    std::string payload = http->httpGetJson("/current");

    DynamicJsonDocument doc(payload.size() * 4);
    DeserializationError err = deserializeJson(doc, payload);

    EXPECT_NE(payload.size(), 0);
    EXPECT_EQ(err, DeserializationError::Ok);
}

TEST_F(HttpPayloadTest, PayloadErrorTest) {
    EXPECT_ANY_THROW(http->httpGetJson("http://api.error.com/v1"));
}

TEST_F(HttpPayloadTest, WeatherCurrentTest) {
    Weather w;
    std::string location = "Rennes";
    DeserializationError err = weatherService->getCurrentWeather(location, &w);

    EXPECT_EQ(err, DeserializationError::Ok);
    EXPECT_FLOAT_EQ(w.temperature, 20.0);
    EXPECT_FLOAT_EQ(w.precipitation, 0.0);
    EXPECT_FLOAT_EQ(w.windKpH, 9.0);
}

TEST_F(HttpPayloadTest, WeatherForecastTest) {
    Weather w;
    std::string location = "Paris";
    DeserializationError err = weatherService->getForecastWeather(location, &w);

    EXPECT_EQ(err, DeserializationError::Ok);
    EXPECT_FLOAT_EQ(w.temperature, 26.3);
    EXPECT_FLOAT_EQ(w.precipitation, 0.0);
    EXPECT_FLOAT_EQ(w.windKpH, 6.5);
}


