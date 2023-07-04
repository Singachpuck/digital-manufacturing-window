#include "WindowCloseState.h"


void WindowCloseState::onEnter(std::map<std::string, void *>& params) {
  this->prevState = (State*) params["prevState"];
  Serial.println("Closing window...");
  Blynk.virtualWrite(V10, "Closing");
}

void WindowCloseState::update() {
  digitalWrite(window->rotateCounterClockPin, HIGH);
  delay(window->rotateTime);
  digitalWrite(window->rotateCounterClockPin, LOW);
  this->sm->change(this->prevState->name, EMPTY_PARAMS);
}

void WindowCloseState::onExit() {
    this->window->openFlag = false;
    Blynk.virtualWrite(V10, "Closed");
}
