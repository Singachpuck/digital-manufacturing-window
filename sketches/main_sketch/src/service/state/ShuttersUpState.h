#ifndef SHUTTERSUPSTATE_H
#define SHUTTERSUPSTATE_H

#include "State.h"


class ShuttersUpState : public State {
public:
    ShuttersUpState(Window* window, Shutters* shutters) : State(States::SHUTTERS_UP, window, shutters) {}

    void onEnter(std::map<std::string, void*>& params) override;

    void update() override;

    void onExit() override;
};


#endif //SHUTTERSUPSTATE_H
