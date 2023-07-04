#ifndef WINDOW_H
#define WINDOW_H


class Window {
public:
    // false - window closed, true - window opened
    bool openFlag = false;

    int rotateClockPin;

    int rotateCounterClockPin;

    int rotateTime;

    Window(int rotateClockPin, int rotateCounterClockPin, int rotateTime) : rotateClockPin(rotateClockPin),
                                                                            rotateCounterClockPin(
                                                                                    rotateCounterClockPin),
                                                                            rotateTime(rotateTime) {}
};


#endif //WINDOW_H
