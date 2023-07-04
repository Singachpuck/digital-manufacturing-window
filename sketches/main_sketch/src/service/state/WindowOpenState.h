#ifndef WINDOWOPENSTATE_H
#define WINDOWOPENSTATE_H

#include "State.h"

/**
 * State during which the window opens.
 */
class WindowOpenState : public State {
public:
    WindowOpenState(Window* window, Shutters* shutters) : State(States::WINDOW_OPEN, window, shutters) {}

    void update() override;

    void onEnter(std::map<std::string, void*>& params) override;

    void onExit() override;
};


#endif //WINDOWOPENSTATE_H
