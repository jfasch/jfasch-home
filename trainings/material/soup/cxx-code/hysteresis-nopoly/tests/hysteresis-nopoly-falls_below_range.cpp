#include <gtest/gtest.h>
#include <sensor-mock-nopoly.h>
#include <switch-mock-nopoly.h>
#include <hysteresis-nopoly.h>

TEST(hysteresis_suite, falls_below_range)
{
    MockSensor_nopoly sensor(30.2);
    MockSwitch_nopoly switcH(MockSwitch_nopoly::OFF);

    Hysteresis_nopoly hyst(&sensor, &switcH, 
                           20.1, 30.4);                // <--- initially within range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch_nopoly::OFF);

    sensor.set_temperature(20.0);                      // <--- falls below range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch_nopoly::ON);
}
