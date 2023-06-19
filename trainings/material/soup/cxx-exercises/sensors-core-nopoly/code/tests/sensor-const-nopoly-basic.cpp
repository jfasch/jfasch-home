#include <gtest/gtest.h>
#include <sensor-const-nopoly.h>

TEST(sensor_const_nopoly_suite, basic)
{
    ConstantSensor_nopoly cs(36.4);

    ASSERT_FLOAT_EQ(cs.get_temperature(), 36.4);       // <--- Sensor interface
    ASSERT_FLOAT_EQ(cs.value(), 36.4);                 // <--- ConstantSensor specific interface
}
