#ifndef STATE_H
#define STATE_H

#include <vector>

#include "Arduino.h"
#include "../event/IEventListener.h"

class StateMachine;

class State : public IEventListener {
public:
    enum States {
        EMPTY, MANUAL, AUTOMATIC, WINDOW_OPEN, WINDOW_CLOSE, SHUTTERS_UP, SHUTTERS_DOWN
    };

    States name;
    StateMachine* sm;

    State(States name) : name(name) {}

    virtual void onEnter() = 0;
    virtual void update() = 0;
    virtual void onExit() = 0;
    void onEvent(Event* event) override {};
};

class EmptyState : public State {
public:
    EmptyState() : State(States::EMPTY) {};

    void update() override;
    void onEnter() override;
    void onExit() override;
};

class StateMachine : public IEventListener {
private:
    std::vector<State*> states {};
    State* currentState;
    EmptyState emptyState;

public:
    StateMachine() : currentState(&emptyState) {};

    void addState(State* state);
    void update();
    void change(State::States stateName);
    void onEvent(Event *event) override;
};

#endif //STATE_H
