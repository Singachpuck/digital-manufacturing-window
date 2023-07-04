#ifndef EVENTPUBLISHER_H
#define EVENTPUBLISHER_H

#include <vector>

#include "Event.h"
#include "IEventListener.h"

/**
 * EventPublisher is responsible for publishing events.
 * Whenever certain event is published, publisher triggers it's listeners to react on the event.
 */
class EventPublisher {
private:
    std::vector<IEventListener*> listeners {};

public:
    /**
     * Subscribes listener to listen for events.
     * @param listener listener to subscribe.
     */
    void subscribe(IEventListener* listener);

    /**
     * Publishes event end triggers it's listeners.
     * @param event event to publish.
     */
    void publish(Event& event);
};


#endif //EVENTPUBLISHER_H
