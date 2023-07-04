#ifndef SHUTTERSUPDOWNEVENT_H
#define SHUTTERSUPDOWNEVENT_H


#include "Event.h"

/**
 * This event is published every time shutters state change is triggerred.
 */
class ShuttersUpDownEvent : public Event {
public:
    int stateValue;

    ShuttersUpDownEvent(int stateValue) : Event(EventType::SHUTTERS_UP_DOWN), stateValue(stateValue) {}
};


#endif //SHUTTERSUPDOWNEVENT_H
