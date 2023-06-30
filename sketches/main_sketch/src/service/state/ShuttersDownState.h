#ifndef SHUTTERSDOWNSTATE_H
#define SHUTTERSDOWNSTATE_H

#include "State.h"


class ShuttersDownState : public State {
public:
    ShuttersDownState() : State(States::SHUTTERS_DOWN) {}

    void onEnter() override;

    void update() override;

    void onExit() override;
};


#endif //SHUTTERSDOWNSTATE_H
