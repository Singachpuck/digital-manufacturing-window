#include "ShuttersDownState.h"

void ShuttersDownState::onEnter(std::map<std::string, void *>& params) {
  this->prevState = (State*) params["prevState"];
  Serial.println("Rolling down shutters...");
  Blynk.virtualWrite(V11, "Rolling");
}

void ShuttersDownState::update() {
  delay(2000);
  this->sm->change(this->prevState->name, EMPTY_PARAMS);
}

void ShuttersDownState::onExit() {
  this->shutters->rollFlag = true;
  Blynk.virtualWrite(V11, "Down");
}
