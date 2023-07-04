#ifndef WEATHERUPDATEEVENT_H
#define WEATHERUPDATEEVENT_H

#include "Event.h"


class WeatherUpdateEvent : public Event {
public:
    WeatherUpdateEvent() : Event(EventType::WEATHER_UPDATE) {}
};

#endif //WEATHERUPDATEEVENT_H
