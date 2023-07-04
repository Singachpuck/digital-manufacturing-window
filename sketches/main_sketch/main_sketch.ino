#include <ArduinoJson.h>
#include <BlynkSimpleEsp8266.h>

#include "src/service/impl/Esp8266WifiService.h"
#include "src/service/impl/Esp8266HttpService.h"
#include "src/service/impl/DefaultWeatherService.h"
#include "src/model/Weather.h"
#include "src/model/Window.h"
#include "src/model/Shutters.h"
#include "src/service/state/State.h"
#include "src/service/state/ManualListeningState.h"
#include "src/service/state/AutomaticListeningState.h"
#include "src/service/state/WindowOpenState.h"
#include "src/service/state/WindowCloseState.h"
#include "src/service/state/ShuttersDownState.h"
#include "src/service/state/ShuttersUpState.h"

#include "src/service/event/EventPublisher.h"
#include "src/service/event/ChangeListeningStateEvent.h"
#include "src/service/event/ShuttersUpDownEvent.h"
#include "src/service/event/WindowOpenCloseEvent.h"
#include "src/service/event/WeatherUpdateEvent.h"

#define WEATHER_UPDATE_INTERVAL 600000L
#define WINDOW_ROTATE_TIME 2000

BlynkTimer timer;

// Services
WiFiClient wifiClient;
HTTPClient httpClient;
Esp8266WifiService wifiService;
Esp8266HttpService httpService(&wifiClient, &httpClient);
DefaultWeatherService weatherService(&httpService, WEATHER_API_ENDPOINT, WEATHER_API_KEY);

// Model
Weather weather(DEVICE_LOCATION);
Window window(D0, D1, WINDOW_ROTATE_TIME);
Shutters shutters; // Shutters not supported for now

// States configuration
ManualListeningState manualState(&window, &shutters);
AutomaticListeningState automaticState(&weather, &window, &shutters);
WindowOpenState windowOpenState(&window, &shutters);
WindowCloseState windowCloseState(&window, &shutters);
ShuttersDownState shuttersDownState(&window, &shutters);
ShuttersUpState shuttersUpState(&window, &shutters);
StateMachine sm;

EventPublisher ep;

// This function is called every time when Listening State button
// changes it's state in Blynk dashboard
BLYNK_WRITE(V0) {
  ChangeListeningStateEvent e(param.asInt());
  ep.publish(e);
}

// This function is called every time when Window button
// changes it's state in Blynk dashboard
BLYNK_WRITE(V1) {
  WindowOpenCloseEvent e(param.asInt());
  ep.publish(e);
}

// This function is called every time when Shutters button
// changes it's state in Blynk dashboard
BLYNK_WRITE(V2) {
  ShuttersUpDownEvent e(param.asInt());
  ep.publish(e);
}

// This function is called every 10 minutes to update Weather
// object according to the current weather
void weatherUpdate() {
  Serial.println("Calling weather forecast...");
  weatherService.updateWeather(&weather);
  Serial.println();
  Serial.println("Weather:");
  Serial.print("Temperature: ");
  Serial.println(weather.temperature);
  Serial.print("Precipitation: ");
  Serial.println(weather.precipitation);
  Serial.print("Wind KpH: ");
  Serial.println(weather.windKpH);
  Serial.println();
  WeatherUpdateEvent weatherUpdateEvent;
  ep.publish(weatherUpdateEvent);
}

// Defines if the WiFi connection was successful
bool connected = false;

void setup() {
  Serial.begin(9600);
  delay(500);
  connected = wifiService.connectToWiFi(50) == WL_CONNECTED;

  Blynk.config(BLYNK_AUTH_TOKEN);

  // Fill up State Machine with all possible states
  sm.addState(&manualState);
  sm.addState(&automaticState);
  sm.addState(&windowOpenState);
  sm.addState(&windowCloseState);
  sm.addState(&shuttersDownState);
  sm.addState(&shuttersUpState);

  ep.subscribe(&sm);

  sm.change(State::States::MANUAL, EMPTY_PARAMS);

  // Make sure that window is closed while bootstrapping the app
  window.openFlag = false;
  Blynk.virtualWrite(V10, "Closed");
  // Make sure that shutters are rolled up before bootstrapping the app
  shutters.rollFlag = false;
  Blynk.virtualWrite(V11, "Up");

  // Update weather every 10 minutes
  weatherUpdate();
  timer.setInterval(WEATHER_UPDATE_INTERVAL, weatherUpdate);
}

void loop() {
  if (connected) {
    // These 2 lines are required by Blynk
    Blynk.run();
    timer.run();

    // Update the current state of State Machine
    sm.update();
  } else {
    Serial.println("Failed to connect to WiFi. Can not proceed!");
    delay(2000);
  }
}
