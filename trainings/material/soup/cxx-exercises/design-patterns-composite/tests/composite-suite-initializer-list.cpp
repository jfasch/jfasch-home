#include <gtest/gtest.h>

#include <sensor-const.h>
#include <sensor-avg.h>


TEST(composite_suite, initializer_list)
{
    ConstantSensor cs1(3);
    ConstantSensor cs2(4);

    AveragingSensor avg{&cs1, &cs2};

    ASSERT_FLOAT_EQ(avg.get_temperature(), 3.5);
}
