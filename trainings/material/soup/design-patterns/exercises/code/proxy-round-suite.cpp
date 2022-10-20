#include <gtest/gtest.h>

#include "sensor-round.h"
#include "sensor-const.h"


TEST(proxy_round_suite, round_down)
{
    ConstantSensor cs(36.34);
    RoundingSensor rs(&cs);        // <--- use measurement from cs for rounding

    ASSERT_FLOAT_EQ(rs.get_temperature(), 36);
}

TEST(proxy_round_suite, round_up)
{
    ConstantSensor cs(36.56);
    RoundingSensor rs(&cs);        // <--- use measurement from cs for rounding

    ASSERT_FLOAT_EQ(rs.get_temperature(), 37);
}

TEST(proxy_round_suite, rouding_sensor__is_a__sensor)
{
    ConstantSensor cs(36.56);
    RoundingSensor rs(&cs);
    Sensor* s = &rs;               // <--- RoundingSensor is-a Sensor

    ASSERT_FLOAT_EQ(s->get_temperature(), 37);
}
