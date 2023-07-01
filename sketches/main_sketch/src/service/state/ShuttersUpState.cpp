#include "ShuttersUpState.h"

void ShuttersUpState::onEnter(std::map<std::string, void *>& params) {
  this->prevState = (State*) params["prevState"];
  Serial.println("Rolling up shutters...");
  Blynk.virtualWrite(V11, "Rolling");
}

void ShuttersUpState::update() {
  delay(2000);
  this->sm->change(this->prevState->name, EMPTY_PARAMS);
}

void ShuttersUpState::onExit() {
  this->shutters->rollFlag = false;
  Blynk.virtualWrite(V11, "Up");
}