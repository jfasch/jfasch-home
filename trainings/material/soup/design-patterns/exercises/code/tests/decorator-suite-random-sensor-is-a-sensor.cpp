#include <gtest/gtest.h>

#include <sensor-decorated-random.h>


TEST(decorator_suite, decorated_sensor_random__is_a__sensor)
{
    DecoratedRandomSensor r("my-funny-random-sensor", 33.3, 40.5);

    ASSERT_GE(r.get_temperature(), 33.3);                      // <--- appears to be-a Sensor
    ASSERT_LE(r.get_temperature(), 40.5);                      // <--- appears to be-a Sensor
    Sensor* s = &r;                                            // <--- is-a Sensor
    ASSERT_GE(s->get_temperature(), 33.3);                     // <--- used as-a Sensor
    ASSERT_LE(s->get_temperature(), 40.5);                     // <--- used as-a Sensor
}
