#ifndef AUTOMATICLISTENINGSTATE_H
#define AUTOMATICLISTENINGSTATE_H

#include "State.h"
#include "../event/ChangeListeningStateEvent.h"
#include "../event/WeatherUpdateEvent.h"
#include "../../model/Weather.h"

/**
 * State that represent Automatic listening mode of the system.
 * While in this state, the model listens to it's sensors and update the window based on the sensor data.
 */
class AutomaticListeningState : public State {

public:
    Weather* weather;

    AutomaticListeningState(Weather* weather, Window* window, Shutters* shutters) : State(States::AUTOMATIC, window, shutters), weather(weather) {}

    void update() override;

    void onEnter(std::map<std::string, void*>& params) override;

    void onExit() override;

    void onEvent(Event *event) override;
};


#endif //AUTOMATICLISTENINGSTATE_H
