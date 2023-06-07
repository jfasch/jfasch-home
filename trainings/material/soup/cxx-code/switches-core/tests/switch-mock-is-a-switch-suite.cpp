#include <gtest/gtest.h>

#include <switch-mock.h>


TEST(switch_mock_suite, is_a_switch)
{
    MockSwitch msw;
    Switch* sw = &msw;
    ASSERT_EQ(sw->state(), MockSwitch::State::OFF);
    sw->on();
    ASSERT_EQ(sw->state(), MockSwitch::State::ON);
    sw->off();
    ASSERT_EQ(sw->state(), MockSwitch::State::OFF);
}
