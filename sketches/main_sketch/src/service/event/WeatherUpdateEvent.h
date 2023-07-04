#ifndef WEATHERUPDATEEVENT_H
#define WEATHERUPDATEEVENT_H

#include "Event.h"

/**
 * This event is published every time the weather has been updated.
 */
class WeatherUpdateEvent : public Event {
public:
    WeatherUpdateEvent() : Event(EventType::WEATHER_UPDATE) {}
};

#endif //WEATHERUPDATEEVENT_H
