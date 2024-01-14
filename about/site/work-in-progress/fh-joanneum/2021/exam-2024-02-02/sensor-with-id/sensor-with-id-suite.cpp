#include <gtest/gtest.h>
#include "sensor-w1.h"

TEST(sensor_with_id_suite, whats_wrong)
{
    W1Sensor sensor(/*id*/ 666,                        // <--- unused
                    /*w1_address*/ 0xdeadbeefUL);

    double temperature = sensor.get_temperature();
    ASSERT_FLOAT_EQ(temperature, 36.5);
}
