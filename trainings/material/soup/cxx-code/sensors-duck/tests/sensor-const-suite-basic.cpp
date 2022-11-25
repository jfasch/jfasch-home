#include <sensor-const.h>

#include <gtest/gtest.h>


TEST(sensor_const_suite, basic)
{
    ConstantSensor cs(36.4);

    ASSERT_FLOAT_EQ(cs.get_temperature(), 36.4);   // <--- (future) Sensor interface
    ASSERT_FLOAT_EQ(cs.value(), 36.4);             // <--- ConstantSensor specific interface
}
