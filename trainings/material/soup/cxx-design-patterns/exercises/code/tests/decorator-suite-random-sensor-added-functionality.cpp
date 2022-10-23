#include <gtest/gtest.h>

#include <sensor-decorated-random.h>


TEST(decorator_suite, decorated_sensor_random_added_functionality)
{
    DecoratedRandomSensor r("my-funny-random-sensor", 33.3, 40.5);

    ASSERT_EQ(r.description(), "RandomSensor(33.3, 40.5)");    // <--- appears to be a DecoratedSensor
    ASSERT_EQ(r.name(), "my-funny-random-sensor");             //                -"-

    DecoratedSensor* ds = &r;                                  // <--- is-a DecoratedSensor
    ASSERT_EQ(ds->description(), "RandomSensor(33.3, 40.5)");  // <--- used as-a DecoratedSensor
    ASSERT_EQ(ds->name(), "my-funny-random-sensor");           // <---           -"-
}
