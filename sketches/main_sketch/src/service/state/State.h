#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#define NO_GLOBAL_BLYNK
#include <BlynkSimpleEsp8266.h>
#include <vector>
#include <map>
#include <string>

#include "../event/IEventListener.h"
#include "../../model/Window.h"
#include "../../model/Shutters.h"

class StateMachine;
class EmptyState;

extern std::map<std::string, void*> EMPTY_PARAMS;
extern EmptyState EMPTY_STATE;

class State : public IEventListener {
public:
    enum States {
        EMPTY,
        MANUAL,
        AUTOMATIC,
        WINDOW_OPEN,
        WINDOW_CLOSE,
        SHUTTERS_UP,
        SHUTTERS_DOWN
    };

    States name;
    Window* window;
    Shutters* shutters;
    StateMachine* sm = nullptr;
    State* prevState = nullptr;

    State(States name, Window* window, Shutters* shutters) : name(name), window(window), shutters(shutters) {}

    virtual void onEnter(std::map<std::string, void*>&) = 0;
    virtual void update() = 0;
    virtual void onExit() = 0;
    void onEvent(Event* event) override {};
};

class EmptyState : public State {
public:
    EmptyState() : State(States::EMPTY, nullptr, nullptr) {};

    void update() override;
    void onEnter(std::map<std::string, void*>& params) override;
    void onExit() override;
};

class StateMachine : public IEventListener {
private:
    std::vector<State*> states {};
    State* currentState;

public:
    StateMachine() : currentState(&EMPTY_STATE) {};

    void addState(State* state);
    void update();
    void change(State::States stateName, std::map<std::string, void*>& params);
    void onEvent(Event *event) override;
};

#endif //STATE_H
