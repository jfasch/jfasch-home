#include <sensor-random.h>

#include <gtest/gtest.h>


TEST(sensor_random_suite, is_a_sensor)
{
    RandomSensor rs(36.4, 42.3);

    Sensor* s = &rs;                     // <--- ConstantSensor is-a Sensor

    // avoid "unused" warning
    (void)s;
}
