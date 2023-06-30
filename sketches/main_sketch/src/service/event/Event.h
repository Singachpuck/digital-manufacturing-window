#ifndef EVENT_H
#define EVENT_H


class Event {
public:
    enum EventType {
        CHANGE_LISTENING_STATE,
        WINDOW_OPEN_CLOSE,
        SHUTTERS_UP_DOWN,
        EMPTY
    };

    EventType type;

    Event() : type(EventType::EMPTY) {}

    Event(EventType type) : type(type) {}

    virtual ~Event() = default;
};


#endif //EVENT_H
