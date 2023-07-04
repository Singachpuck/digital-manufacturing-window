#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "Event.h"

/**
 * IEventListener interface makes certain class wait
 * for a certain event and react on it on occurrence.
 */
class IEventListener {
public:
    /**
     * Function that handles published event.
     * @param event event to handle.
     */
    virtual void onEvent(Event* event) = 0;
};


#endif //EVENTLISTENER_H
