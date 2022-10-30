#include <gtest/gtest.h>

#include <sensor-const.h>
#include <sensor-utils.h>


TEST(sensor_utils_suite, average)
{
    ConstantSensor c1(3);
    ConstantSensor c2(4);
    ConstantSensor c3(5);

    auto sensors = std::vector<Sensor*>{&c1, &c2, &c3};
    ASSERT_FLOAT_EQ(average(sensors.begin(), sensors.end()), 4);
}
