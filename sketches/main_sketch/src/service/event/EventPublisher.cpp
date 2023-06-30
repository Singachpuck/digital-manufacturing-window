#include "EventPublisher.h"

void EventPublisher::publish(Event& event) {
    for (IEventListener* listener : this->listeners) {
        listener->onEvent(&event);
    }
}

void EventPublisher::subscribe(IEventListener* listener) {
    this->listeners.push_back(listener);
}
