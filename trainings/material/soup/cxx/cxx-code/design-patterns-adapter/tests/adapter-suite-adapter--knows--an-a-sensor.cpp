#include <gtest/gtest.h>

#include <sensor-fahrenheit.h>
#include <sensor-fahrenheit-const.h>
#include <sensor-fahrenheit-adapter.h>
#include <sensor.h>

TEST(adapter_suite, adapter__knows__an_a_sensor)
{
    ConstantFahrenheitSensor fcs(36.5);
    FahrenheitSensor* fs = &fcs;            // <--- convert to root of A's sensor hierarchy

    FahrenheitSensor_Adapter adapter(fs);

    Sensor* sensor = &adapter;              // <--- is-a Sensor

    // suppress "unused" warning
    (void)sensor;
}
