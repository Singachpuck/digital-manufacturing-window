#ifndef WINDOWCLOSESTATE_H
#define WINDOWCLOSESTATE_H

#include "State.h"


class WindowCloseState : public State {
public:
    WindowCloseState() : State(States::WINDOW_CLOSE) {}

    void update() override;

    void onEnter() override;

    void onExit() override;

    void onEvent(Event *event) override;
};


#endif //WINDOWCLOSESTATE_H
