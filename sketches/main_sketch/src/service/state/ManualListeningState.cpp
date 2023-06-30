#include "ManualListeningState.h"

void ManualListeningState::update() {
//    Serial.println("Hello from Serial");
}

void ManualListeningState::onEnter() {
    Serial.println("Manual state enabled!");
}

void ManualListeningState::onExit() {

}

void ManualListeningState::onEvent(Event *event) {
  if (auto *e = dynamic_cast<ChangeListeningStateEvent *>(event)) {
    if (e->stateValue == 1) {
      this->sm->change(AUTOMATIC);
    }
  } else if (auto *e = dynamic_cast<WindowOpenCloseEvent *>(event)) {
    if (e->stateValue == 0) {
      this->sm->change(WINDOW_CLOSE);
    } else if (e->stateValue == 1) {
      this->sm->change(WINDOW_OPEN);
    }
  } else if (auto *e = dynamic_cast<ShuttersUpDownEvent *>(event)) {
    if (e->stateValue == 0) {
      this->sm->change(SHUTTERS_UP);
    } else if (e->stateValue == 1) {
      this->sm->change(SHUTTERS_DOWN);
    }
  }
}
