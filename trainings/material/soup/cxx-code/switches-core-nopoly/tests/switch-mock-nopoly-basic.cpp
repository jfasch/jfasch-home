#include <gtest/gtest.h>

#include <switch-mock-nopoly.h>


TEST(switch_mock_suite, initial_state)
{
    {
        MockSwitch_nopoly sw(MockSwitch_nopoly::State::OFF);
        ASSERT_TRUE(sw.state() == MockSwitch_nopoly::State::OFF);
    }
    {
        MockSwitch_nopoly sw(MockSwitch_nopoly::State::ON);
        ASSERT_TRUE(sw.state() == MockSwitch_nopoly::State::ON);
    }
}

TEST(switch_mock_suite, set_on_off)
{
    MockSwitch_nopoly sw(MockSwitch_nopoly::State::OFF);
    ASSERT_TRUE(sw.state() == MockSwitch_nopoly::State::OFF);
    sw.on();
    ASSERT_TRUE(sw.state() == MockSwitch_nopoly::State::ON);
    sw.off();
    ASSERT_TRUE(sw.state() == MockSwitch_nopoly::State::OFF);
}
