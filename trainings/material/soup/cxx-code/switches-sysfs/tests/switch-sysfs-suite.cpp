#include <gtest/gtest.h>

#include <switch-mock.h>


TEST(switch_mock_suite, basic)
{
    MockSwitch sw;
    ASSERT_TRUE(sw.state() == Switch::State::OFF);
    sw.on();
    ASSERT_TRUE(sw.state() == Switch::State::ON);
    sw.off();
    ASSERT_TRUE(sw.state() == Switch::State::OFF);
}

TEST(switch_mock_suite, is_a_switch)
{
    MockSwitch msw;
    Switch* sw = &msw;
    ASSERT_EQ(sw->state(), Switch::State::OFF);
    sw->on();
    ASSERT_EQ(sw->state(), Switch::State::ON);
    sw->off();
    ASSERT_EQ(sw->state(), Switch::State::OFF);
}
