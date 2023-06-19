#include <gtest/gtest.h>

#include <sensor-avg-nopoly.h>
#include <sensor-mock-nopoly.h>


TEST(sensor_avg_nopoly_suite, basic)
{
    ConstantSensor cs1(3);
    ConstantSensor cs2(4);

    Sensor* s1 = &cs1;     // <--- is-a Sensor
    Sensor* s2 = &cs2;     // <--- is-a Sensor

    AveragingSensor avg;   // <-- uses-many Sensor
    avg.add(s1);
    avg.add(s2);

    Sensor* s = &avg;      // <-- is-a Sensor
    ASSERT_FLOAT_EQ(s->get_temperature(), 3.5);
}
