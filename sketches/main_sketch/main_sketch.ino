#include <BlynkSimpleEsp8266.h>

#include "src/service/impl/Esp8266WifiService.h"
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

BlynkTimer timer;

DefaultWifiService wifiService;

// Model
Window window;
Shutters shutters;

// States configuration
ManualListeningState manualState(&window, &shutters);
AutomaticListeningState automaticState(&window, &shutters);
WindowOpenState windowOpenState(&window, &shutters);
WindowCloseState windowCloseState(&window, &shutters);
ShuttersDownState shuttersDownState(&window, &shutters);
ShuttersUpState shuttersUpState(&window, &shutters);
StateMachine sm;

EventPublisher ep;


BLYNK_WRITE(V0) {
  ChangeListeningStateEvent e(param.asInt());
  ep.publish(e);
}

BLYNK_WRITE(V1) {
  WindowOpenCloseEvent e(param.asInt());
  ep.publish(e);
}

BLYNK_WRITE(V2) {
  ShuttersUpDownEvent e(param.asInt());
  ep.publish(e);
}

bool connected = false;

void setup() {
  Serial.begin(9600);
  delay(500);
  connected = wifiService.connectToWiFi(50) == WL_CONNECTED;

  Blynk.config(BLYNK_AUTH_TOKEN);

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
}

void loop() {
  if (connected) {
    Blynk.run();
    timer.run();

    sm.update();
  } else {
    Serial.println("Failed to connect to WiFi. Can not proceed!");
    delay(2000);
  }
}
