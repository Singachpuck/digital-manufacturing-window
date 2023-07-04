#ifndef EVENT_H
#define EVENT_H

/**
 * Base class for the event.
 * Defines enum with all the possible event types that may occur.
 * Used by event publisher to publish certain event.
 */
class Event {
public:
    enum EventType {
        CHANGE_LISTENING_STATE,
        WINDOW_OPEN_CLOSE,
        SHUTTERS_UP_DOWN,
        WEATHER_UPDATE,
        EMPTY
    };

    EventType type;

    Event() : type(EventType::EMPTY) {}

    Event(EventType type) : type(type) {}

    virtual ~Event() = default;
};


#endif //EVENT_H
