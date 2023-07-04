#ifndef WINDOWOPENCLOSEEVENT_H
#define WINDOWOPENCLOSEEVENT_H


#include "Event.h"

/**
 * This event is published every time window state change is triggerred.
 */
class WindowOpenCloseEvent : public Event {
public:
    int stateValue;

    WindowOpenCloseEvent(int stateValue) : Event(EventType::WINDOW_OPEN_CLOSE), stateValue(stateValue) {}
};


#endif //WINDOWOPENCLOSEEVENT_H
