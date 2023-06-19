#include <gtest/gtest.h>
#include <sensor-mock-nopoly.h>
#include <switch-mock-nopoly.h>
#include <hysteresis-nopoly.h>

TEST(hysteresis_suite, rises_above_range_when_on)
{
    MockSensor_nopoly sensor(30.2);
    MockSwitch_nopoly switcH(MockSwitch_nopoly::OFF);

    Hysteresis_nopoly hyst(&sensor, &switcH, 20.1, 30.4);

    sensor.set_temperature(-273.15);                   // <--- ensure that switch will be 
                                                       //      on after next check()

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch_nopoly::ON);

    sensor.set_temperature(35);                        // <--- rises above range

    hyst.check();
    ASSERT_EQ(switcH.state(), MockSwitch_nopoly::OFF);
}
