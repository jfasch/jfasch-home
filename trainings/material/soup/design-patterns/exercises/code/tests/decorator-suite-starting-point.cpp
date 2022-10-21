#include <gtest/gtest.h>

#include <sensor-const.h>
#include <sensor-utils.h>


TEST(decorator_suite, average_with_base_sensor)
{
    ConstantSensor c1(42);
    ConstantSensor c2(666);

    std::vector<Sensor*> sensors{&c1, &c2};

    ASSERT_FLOAT_EQ(average(sensors.begin(), sensors.end()), 354);
}

