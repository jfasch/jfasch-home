#include <gtest/gtest.h>

#include <sensor-fahrenheit.h>          // <--- company A's sensor interface
#include <sensor-fahrenheit-const.h>    // <--- one of their sensors
#include <sensor-fahrenheit-adapter.h>  // <--- to be implemented
#include <sensor.h>                     // <--- our sensor interface

TEST(adapter_suite, basic)
{
    // buy most sophisticated sensor from A, and see if it works
    ConstantFahrenheitSensor fs(36.5);
    ASSERT_FLOAT_EQ(fs.get_temperature_f(), 36.5);

    // adapt it into our hierarchy, converting its Fahrenheit
    // measurement into Celsius
    FahrenheitSensor_Adapter adapter(&fs);
    ASSERT_FLOAT_EQ(adapter.get_temperature(), (36.5 - 32) * 5/9);
}
