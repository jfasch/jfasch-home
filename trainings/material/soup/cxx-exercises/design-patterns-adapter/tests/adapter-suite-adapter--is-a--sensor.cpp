#include <gtest/gtest.h>

#include <sensor-fahrenheit.h>
#include <sensor-fahrenheit-const.h>
#include <sensor-fahrenheit-adapter.h>
#include <sensor.h>

TEST(adapter_suite, adapter__is_a__sensor)
{
    ConstantFahrenheitSensor fs(36.5);
    FahrenheitSensor_Adapter adapter(&fs);

    Sensor* sensor = &adapter;                 // <--- is-a Sensor

    // suppress "unused" warning
    (void)sensor;
}
