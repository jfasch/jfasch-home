#include <sensor-const.h>

#include <gtest/gtest.h>


TEST(sensor_const_suite, is_a_sensor)
{
    ConstantSensor cs(36.4);

    Sensor* s = &cs;                                   // <--- ConstantSensor is-a Sensor

    // avoid "unused' warning
    (void)s;
}
