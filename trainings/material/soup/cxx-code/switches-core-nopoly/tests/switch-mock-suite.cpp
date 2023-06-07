#include <gtest/gtest.h>

#include <switch-mock.h>


TEST(switch_mock_suite, basic)
{
    MockSwitch sw;
    ASSERT_TRUE(sw.state() == MockSwitch::State::OFF);
    sw.on();
    ASSERT_TRUE(sw.state() == MockSwitch::State::ON);
    sw.off();
    ASSERT_TRUE(sw.state() == MockSwitch::State::OFF);
}
