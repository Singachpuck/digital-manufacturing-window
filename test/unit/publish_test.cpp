#include "gtest/gtest.h"
#include "MockEventListener.h"

#include "service/event/EventPublisher.h"

using namespace ::testing;

TEST(PublishTest, NullTest) {
    MockEventListener el;
    EXPECT_CALL(el, onEvent(nullptr))
    .Times(1)
    .WillRepeatedly(Throw(std::exception()));

    EXPECT_ANY_THROW(el.onEvent(nullptr));
}

TEST(PublishTest, ListenTest) {
  MockEventListener el;
  EXPECT_CALL(el, onEvent(_))
          .Times(1);

  EventPublisher ep;
  ep.subscribe(&el);

  Event event(Event::EMPTY);
  ep.publish(event);
}