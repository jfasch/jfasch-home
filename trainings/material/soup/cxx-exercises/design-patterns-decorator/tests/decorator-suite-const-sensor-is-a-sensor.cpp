#include <gtest/gtest.h>

#include <sensor-decorated-const.h>


TEST(decorator_suite, decorated_sensor_const__is_a__sensor)
{
    DecoratedConstantSensor c("my-funny-const-sensor", 38.6);

    Sensor* s = &c;                                            // <--- is-a Sensor
    ASSERT_FLOAT_EQ(s->get_temperature(), 38.6);               // <--- used as-a Sensor
}

