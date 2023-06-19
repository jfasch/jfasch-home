#include <sensor-mock.h>

#include <gtest/gtest.h>


TEST(sensor_mock_suite, is_a_sensor)
{
    MockSensor ms(36.4);

    Sensor* s = &ms;                                   // <--- MockSensor is-a Sensor

    // avoid "unused' warning
    (void)s;
}
