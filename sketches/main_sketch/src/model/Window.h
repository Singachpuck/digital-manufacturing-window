#ifndef WINDOW_H
#define WINDOW_H

/**
 * Represents window structure.
 * Class contains the following fields:
 * - openFlag: represent current state of the window (open/close)
 * - rotateClockPin: pin to rotate dc motor clockwise
 * - rotateCounterClockPin: pin to rotate dc motor counter clockwise
 * - rotateTime: time in milliseconds to define the duration of rotation to change window state
 */
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
