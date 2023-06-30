#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "Event.h"

class IEventListener {
public:
    virtual void onEvent(Event* event) = 0;
};


#endif //EVENTLISTENER_H
