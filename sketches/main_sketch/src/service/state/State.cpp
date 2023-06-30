#include "State.h"

void StateMachine::update() {
    this->currentState->update();
}

void StateMachine::change(State::States stateName) {
    for (State* state : this->states) {
        if (state->name == stateName) {
            this->currentState->onExit();
            this->currentState = state;
            this->currentState->onEnter();
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

void EmptyState::onEnter() {}

void EmptyState::onExit() {}
