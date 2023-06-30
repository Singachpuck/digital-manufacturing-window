#ifndef EVENTPUBLISHER_H
#define EVENTPUBLISHER_H

#include <vector>

#include "Event.h"
#include "IEventListener.h"

class EventPublisher {
private:
    std::vector<IEventListener*> listeners {};

public:
    void subscribe(IEventListener* listener);

    void publish(Event& event);
};


#endif //EVENTPUBLISHER_H
