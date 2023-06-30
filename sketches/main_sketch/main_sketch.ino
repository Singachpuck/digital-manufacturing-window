#include <BlynkSimpleEsp8266.h>

#include "src/service/impl/Esp8266WifiService.h"
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

// States configuration
ManualListeningState manualState;
AutomaticListeningState automaticState;
WindowOpenState windowOpenState;
WindowCloseState windowCloseState;
ShuttersDownState shuttersDownState;
ShuttersUpState shuttersUpState;
StateMachine sm;

EventPublisher ep;


BLYNK_WRITE(V0) {
  int value = param.asInt();
  ChangeListeningStateEvent e(value);
  ep.publish(e);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  WindowOpenCloseEvent e(value);
  ep.publish(e);
}

BLYNK_WRITE(V2) {
  int value = param.asInt();
  ShuttersUpDownEvent e(value);
  ep.publish(e);
}

bool connected = false;

void setup() {
  Serial.begin(9600);
  delay(1000);
  connected = wifiService.connectToWiFi(50) == WL_CONNECTED;

  Blynk.config(BLYNK_AUTH_TOKEN);

  sm.addState(&manualState);
  sm.addState(&automaticState);
  sm.addState(&windowOpenState);
  sm.addState(&windowCloseState);
  sm.addState(&shuttersDownState);
  sm.addState(&shuttersUpState);

  ep.subscribe(&sm);

  sm.change(State::States::MANUAL);
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
