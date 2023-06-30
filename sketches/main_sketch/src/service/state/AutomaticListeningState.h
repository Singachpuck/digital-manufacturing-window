#ifndef AUTOMATICLISTENINGSTATE_H
#define AUTOMATICLISTENINGSTATE_H

#include "State.h"
#include "../event/ChangeListeningStateEvent.h"

class AutomaticListeningState : public State {

public:
    AutomaticListeningState() : State(States::AUTOMATIC) {}

    void update() override;

    void onEnter() override;

    void onExit() override;

    void onEvent(Event *event) override;
};


#endif //AUTOMATICLISTENINGSTATE_H
