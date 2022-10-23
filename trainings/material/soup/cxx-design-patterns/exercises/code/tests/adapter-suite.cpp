#include <gtest/gtest.h>

#include <sensor-A.h>          // <--- company A's sensor interface
#include <sensor-A-adapt-B.h>  // <--- to be implemented
#include <sensor.h>            // <--- company B's sensor interface
#include <sensor-const.h>      // <--- company B's most sophisticated sensor

TEST(adapter_suite, basic)
{
    // buy most sophisticated sensor from B, and see if it works
    ConstantSensor sensor_from_b(36.5);
    ASSERT_FLOAT_EQ(sensor_from_b.get_temperature(), 36.5);

    // adapt it into A's framework, converting its Celsius measurement
    // into Fahrenheit
    SensorB_Adapter b_adapter(&sensor_from_b);
    ASSERT_FLOAT_EQ(b_adapter.get_temperature(), 36.5 * 5/9 + 32);
}
