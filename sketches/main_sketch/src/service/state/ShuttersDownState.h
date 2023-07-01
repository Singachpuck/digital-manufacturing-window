#ifndef SHUTTERSDOWNSTATE_H
#define SHUTTERSDOWNSTATE_H

#include "State.h"


class ShuttersDownState : public State {
public:
    ShuttersDownState(Window* window, Shutters* shutters) : State(States::SHUTTERS_DOWN, window, shutters) {}

    void onEnter(std::map<std::string, void*>& params) override;

    void update() override;

    void onExit() override;
};


#endif //SHUTTERSDOWNSTATE_H
