#ifndef WINDOWCLOSESTATE_H
#define WINDOWCLOSESTATE_H

#include "State.h"

/**
 * State during which the window closes.
 */
class WindowCloseState : public State {
public:
    WindowCloseState(Window* window, Shutters* shutters) : State(States::WINDOW_CLOSE, window, shutters) {}

    void update() override;

    void onEnter(std::map<std::string, void*>& params) override;

    void onExit() override;
};


#endif //WINDOWCLOSESTATE_H
