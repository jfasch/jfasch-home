#include <gtest/gtest.h>

#include <sensor-A.h>          // <--- company A's sensor interface
#include <sensor-A-const.h>    // <--- one of their sensors
#include <sensor-A-adapter.h>  // <--- to be implemented
#include <sensor.h>            // <--- our sensor interface

TEST(adapter_suite, basic)
{
    // buy most sophisticated sensor from A, and see if it works
    AConstantSensor const_sensor_from_a(36.5);
    ASSERT_FLOAT_EQ(const_sensor_from_a.get_temperature_fahrenheit(), 36.5);

    // adapt it into our hierarchy, converting its Fahrenheit
    // measurement into Celsius
    ASensor_Adapter a_adapter(&const_sensor_from_a);
    ASSERT_FLOAT_EQ(a_adapter.get_temperature(), (36.5 - 32) * 5/9);
}
