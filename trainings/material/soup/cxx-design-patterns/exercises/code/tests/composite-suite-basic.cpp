#include <gtest/gtest.h>

#include <sensor-const.h>
#include <sensor-avg.h>


TEST(composite_suite, basic)
{
    ConstantSensor cs1(3);
    ConstantSensor cs2(4);

    Sensor* s1 = &cs1;     // <--- is-a Sensor
    Sensor* s2 = &cs2;     // <--- is-a Sensor

    AveragingSensor avg;   // <-- uses-many Sensor
    avg.add(s1);
    avg.add(s2);

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);
}
