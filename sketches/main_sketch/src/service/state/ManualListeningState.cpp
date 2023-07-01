#include "ManualListeningState.h"

void ManualListeningState::update() {

}

void ManualListeningState::onEnter(std::map<std::string, void *>& params) {
    Serial.println("Manual state enabled!");
}

void ManualListeningState::onExit() {

}

void ManualListeningState::onEvent(Event *event) {
  std::map<std::string, void*> params {};
  params["prevState"] = this;
  if (auto *e = dynamic_cast<ChangeListeningStateEvent *>(event)) {
    if (e->stateValue == 1) {
      this->sm->change(AUTOMATIC, EMPTY_PARAMS);
    }
  } else if (auto *e = dynamic_cast<WindowOpenCloseEvent *>(event)) {
    if (e->stateValue == 0 && this->window->openFlag) {
      this->sm->change(WINDOW_CLOSE, params);
    } else if (e->stateValue == 1 && !this->window->openFlag) {
      this->sm->change(WINDOW_OPEN, params);
    }
  } else if (auto *e = dynamic_cast<ShuttersUpDownEvent *>(event)) {
    if (e->stateValue == 0 && this->shutters->rollFlag) {
      this->sm->change(SHUTTERS_UP, params);
    } else if (e->stateValue == 1 && !this->shutters->rollFlag) {
      this->sm->change(SHUTTERS_DOWN, params);
    }
  }
}
