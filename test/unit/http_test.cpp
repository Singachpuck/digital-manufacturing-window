#include "gtest/gtest.h"
#include "MockHttpService.h"
#include "service/impl/DefaultWeatherService.h"

using namespace ::testing;

class HttpPayloadTest : public Test {

public:
    std::string defaultPayload = R"({"location":{"name":"Rennes","region":"Bretagne","country":"France","lat":48.11,"lon":-1.68,"tz_id":"Europe/Paris","localtime_epoch":1686867157,"localtime":"2023-06-16 0:12"},"current":{"last_updated_epoch":1686866400,"last_updated":"2023-06-16 00:00","temp_c":20.0,"temp_f":68.0,"is_day":0,"condition":{"text":"Clear","icon":"//cdn.weatherapi.com/weather/64x64/night/113.png","code":1000},"wind_mph":5.6,"wind_kph":9.0,"wind_degree":330,"wind_dir":"NNW","pressure_mb":1019.0,"pressure_in":30.09,"precip_mm":0.0,"precip_in":0.0,"humidity":60,"cloud":0,"feelslike_c":20.0,"feelslike_f":68.0,"vis_km":10.0,"vis_miles":6.0,"uv":1.0,"gust_mph":12.8,"gust_kph":20.5}})";

    MockHttpService* http = nullptr;
    DefaultWeatherService* weatherService = nullptr;

    ~HttpPayloadTest() override {
        delete http;
        delete weatherService;
    }

protected:
    void SetUp() override {
        http = new MockHttpService();
        ON_CALL(*http, httpGetJson(_)).WillByDefault(Return(defaultPayload));

        weatherService = new DefaultWeatherService(*http, "http://api.weatherapi.com/v1", "12345");
    }
};

TEST_F(HttpPayloadTest, PayloadParseTest) {
    std::string payload = http->httpGetJson("/current");

    DynamicJsonDocument doc(payload.size() * 4);

    DeserializationError err = deserializeJson(doc, payload);

    EXPECT_NE(payload.size(), 0);
    EXPECT_EQ(err, DeserializationError::Ok);
}

TEST_F(HttpPayloadTest, WeatherServiceTest) {
    Weather w;
    DeserializationError err = weatherService->getCurrentWeather("Rennes", &w);

    EXPECT_EQ(err, DeserializationError::Ok);
    EXPECT_FLOAT_EQ(w.temperature, 20.0);
    EXPECT_FLOAT_EQ(w.precipitation, 0.0);
    EXPECT_FLOAT_EQ(w.windKpH, 9.0);
}


