#ifndef SHUTTERSUPSTATE_H
#define SHUTTERSUPSTATE_H

#include "State.h"


class ShuttersUpState : public State {
public:
    ShuttersUpState() : State(States::SHUTTERS_UP) {}

    void onEnter() override;

    void update() override;

    void onExit() override;
};


#endif //SHUTTERSUPSTATE_H
