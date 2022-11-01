#include <gtest/gtest.h>

#include <sensor-A.h>
#include <sensor-A-const.h>
#include <sensor-A-adapter.h>
#include <sensor.h>

TEST(adapter_suite, adapter__is_a__sensor)
{
    AConstantSensor const_sensor_from_a(36.5);
    ASensor_Adapter a_adapter(&const_sensor_from_a);

    Sensor* sensor = &a_adapter;                 // <--- is-a Sensor
    (void)sensor; // suppress "unused" warning
}
