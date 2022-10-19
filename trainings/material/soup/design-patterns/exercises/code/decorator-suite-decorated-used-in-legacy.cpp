#include <gtest/gtest.h>

#include "sensor-decorated-const.h"
#include "sensor-utils.h"


TEST(decorator_suite, average_with_decorated_sensor)
{
    DecoratedConstantSensor c1("c1", 42);
    DecoratedConstantSensor c2("c2", 666);

    std::vector<Sensor*> sensors{&c1, &c2};

    ASSERT_FLOAT_EQ(average(sensors.begin(), sensors.end()), 354);
}
