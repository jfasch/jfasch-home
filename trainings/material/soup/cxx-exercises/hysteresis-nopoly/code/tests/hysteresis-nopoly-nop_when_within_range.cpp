#include <gtest/gtest.h>
#include <sensor-mock-nopoly.h>
#include <switch-mock-nopoly.h>
#include <hysteresis-nopoly.h>

TEST(hysteresis_suite, nop_when_within_range)
{
    MockSensor_nopoly sensor(30.2);
    MockSwitch_nopoly switcH(MockSwitch_nopoly::OFF);

    Hysteresis_nopoly hyst(&sensor, &switcH, 20.1, 30.4);

    hyst.check();                                      // <--- sees sensor well within range
    ASSERT_EQ(switcH.state(), MockSwitch_nopoly::OFF);
}
