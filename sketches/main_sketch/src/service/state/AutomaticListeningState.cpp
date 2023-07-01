#include "AutomaticListeningState.h"

void AutomaticListeningState::update() {

}

void AutomaticListeningState::onEnter(std::map<std::string, void *>& params) {
    Serial.println("Automatic state enabled!");
}

void AutomaticListeningState::onExit() {

}

void AutomaticListeningState::onEvent(Event *event) {
  if (auto *e = dynamic_cast<ChangeListeningStateEvent *>(event)) {
    if (e->stateValue == 0) {
      this->sm->change(MANUAL, EMPTY_PARAMS);
    }
  }
}
