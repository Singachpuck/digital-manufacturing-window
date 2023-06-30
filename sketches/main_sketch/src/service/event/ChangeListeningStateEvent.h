#ifndef CHANGELISTENINGSTATEEVENT_H
#define CHANGELISTENINGSTATEEVENT_H


#include "Event.h"

class ChangeListeningStateEvent : public Event {
public:
    int stateValue;

    ChangeListeningStateEvent(int stateValue) : Event(EventType::CHANGE_LISTENING_STATE), stateValue(stateValue) {}
};


#endif //CHANGELISTENINGSTATEEVENT_H
