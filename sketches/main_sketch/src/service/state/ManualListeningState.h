#ifndef MANUALLISTENINGSTATE_H
#define MANUALLISTENINGSTATE_H

#include "State.h"
#include "../event/ChangeListeningStateEvent.h"
#include "../event/WindowOpenCloseEvent.h"
#include "../event/ShuttersUpDownEvent.h"

class ManualListeningState : public State {
public:
    ManualListeningState() : State(States::MANUAL) {}

    void update() override;

    void onEnter() override;

    void onExit() override;

    void onEvent(Event *event) override;
};


#endif //MANUALLISTENINGSTATE_H
