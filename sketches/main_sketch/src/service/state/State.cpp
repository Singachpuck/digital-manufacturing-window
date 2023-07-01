#include "State.h"

std::map<std::string, void*> EMPTY_PARAMS {};
EmptyState EMPTY_STATE;

void StateMachine::update() {
    this->currentState->update();
}

void StateMachine::change(State::States stateName, std::map<std::string, void*>& params) {
    for (State* state : this->states) {
        if (state->name == stateName) {
            this->currentState->onExit();
            this->currentState = state;
            this->currentState->onEnter(params);
            return;
        }
    }
}

void StateMachine::addState(State *state) {
    state->sm = this;
    states.push_back(state);
}

void StateMachine::onEvent(Event *event) {
    this->currentState->onEvent(event);
}

void EmptyState::update() {}

void EmptyState::onEnter(std::map<std::string, void *>& params) {}

void EmptyState::onExit() {}
