#ifndef AUTOMATICLISTENINGSTATE_H
#define AUTOMATICLISTENINGSTATE_H

#include "State.h"
#include "../event/ChangeListeningStateEvent.h"

class AutomaticListeningState : public State {

public:
    AutomaticListeningState(Window* window, Shutters* shutters) : State(States::AUTOMATIC, window, shutters) {}

    void update() override;

    void onEnter(std::map<std::string, void*>& params) override;

    void onExit() override;

    void onEvent(Event *event) override;
};


#endif //AUTOMATICLISTENINGSTATE_H
