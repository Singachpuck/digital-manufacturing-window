#include "WindowOpenState.h"


void WindowOpenState::onEnter(std::map<std::string, void *>& params) {
  this->prevState = (State*) params["prevState"];
  Serial.println("Opening window...");
  Blynk.virtualWrite(V10, "Opening");
}

void WindowOpenState::update() {
    digitalWrite(window->rotateClockPin, HIGH);
    delay(window->rotateTime);
    digitalWrite(window->rotateClockPin, LOW);
    this->sm->change(this->prevState->name, EMPTY_PARAMS);
}

void WindowOpenState::onExit() {
  this->window->openFlag = true;
  Blynk.virtualWrite(V10, "Opened");
}