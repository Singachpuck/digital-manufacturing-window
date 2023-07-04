#ifndef UNIT_TEST_MOCKEVENTLISTENER_H
#define UNIT_TEST_MOCKEVENTLISTENER_H

#include "gmock/gmock.h"

#include "service/event/IEventListener.h"

class MockEventListener : public IEventListener {
public:
    MOCK_METHOD(void, onEvent, (Event* event), (override));
};


#endif //UNIT_TEST_MOCKEVENTLISTENER_H
