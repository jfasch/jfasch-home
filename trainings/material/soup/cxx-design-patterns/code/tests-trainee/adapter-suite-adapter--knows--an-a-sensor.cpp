#include <gtest/gtest.h>

#include <sensor-A.h>
#include <sensor-A-const.h>
#include <sensor-A-adapter.h>
#include <sensor.h>

TEST(adapter_suite, adapter__knows__an_a_sensor)
{
    AConstantSensor const_sensor_from_a(36.5);
    ASensor* a_sensor = &const_sensor_from_a;    // <--- convert to root of A's sensor hierarchy

    ASensor_Adapter a_adapter(a_sensor);

    Sensor* sensor = &a_adapter;                 // <--- is-a Sensor
    (void)sensor; // suppress "unused" warning
}
