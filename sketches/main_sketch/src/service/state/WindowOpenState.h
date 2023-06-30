#ifndef WINDOWOPENSTATE_H
#define WINDOWOPENSTATE_H

#include "State.h"


class WindowOpenState : public State {
public:
    WindowOpenState() : State(States::WINDOW_OPEN) {}

    void update() override;

    void onEnter() override;

    void onExit() override;

    void onEvent(Event *event) override;
};


#endif //WINDOWOPENSTATE_H
