#include "AutomaticListeningState.h"

void AutomaticListeningState::update() {

}

void AutomaticListeningState::onEnter(std::map<std::string, void *>& params) {
    Serial.println("Automatic state enabled!");
}

void AutomaticListeningState::onExit() {

}

void AutomaticListeningState::onEvent(Event *event) {
  std::map<std::string, void*> params {};
  params["prevState"] = this;
  if (auto *e = dynamic_cast<ChangeListeningStateEvent *>(event)) {
    if (e->stateValue == 0) {
      this->sm->change(MANUAL, EMPTY_PARAMS);
    }
  } if (dynamic_cast<WeatherUpdateEvent *>(event)) {
    if ((this->weather->precipitation >= 0.5 || this->weather->windKpH >= 30) && this->window->openFlag) {
      this->sm->change(WINDOW_CLOSE, params);
    } else if (this->weather->temperature >= 26.0 && !this->window->openFlag) {
      this->sm->change(WINDOW_OPEN, params);
    }
  }
}
