#include <gtest/gtest.h>

#include "sensor-decorated-const.h"


TEST(decorator_suite, decorated_sensor_const_added_functionality)
{
    DecoratedConstantSensor c("my-funny-const-sensor", 38.6);

    ASSERT_EQ(c.description(), "ConstantSensor(38.6)");        // <--- appears to be a DecoratedSensor
    ASSERT_EQ(c.name(), "my-funny-const-sensor");              //                -"-

    DecoratedSensor* ds = &c;                                  // <--- is-a DecoratedSensor
    ASSERT_EQ(ds->description(), "ConstantSensor(38.6)");      // <--- used as-a DecoratedSensor
    ASSERT_EQ(ds->name(), "my-funny-const-sensor");            // <---           -"-
}
