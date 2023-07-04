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

/**
 * Base class for each state.
 */
class State : public IEventListener {
public:
    /**
     * Enum that contains names for all the possible states.
     */
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

    /**
     * Method that is called every time the state machine enters this state.
     */
    virtual void onEnter(std::map<std::string, void*>&) = 0;

    /**
     * Method that updates the state. Typically used within Arduino loop method.
     */
    virtual void update() = 0;

    /**
     * Method that is called every time the state machine exits this state.
     */
    virtual void onExit() = 0;

    void onEvent(Event* event) override {};
};

/**
 * Empty state that does nothing.
 */
class EmptyState : public State {
public:
    EmptyState() : State(States::EMPTY, nullptr, nullptr) {};

    void update() override;
    void onEnter(std::map<std::string, void*>& params) override;
    void onExit() override;
};

/**
 * State machine class that is used to switch between different states.
 * Default state is Empty.
 */
class StateMachine : public IEventListener {
private:
    std::vector<State*> states {};
    State* currentState;

public:
    StateMachine() : currentState(&EMPTY_STATE) {};

    /**
     * MEthod to add state to the state machine.
     * @param state pointer to the State.
     */
    void addState(State* state);

    /**
     * Update current state of the machine.
     */
    void update();

    /**
     * Method to change current state of the machine. Here is where onExit and onEnter methods of State class are called.
     * @param stateName name of the state.
     * @param params params map; used to keep track of previous states, for example.
     */
    void change(State::States stateName, std::map<std::string, void*>& params);

    void onEvent(Event *event) override;
};

#endif //STATE_H
