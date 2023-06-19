#include "sensor-w1-factory-fixture.h"
#include <sensor-w1.h>
#include <sensor-w1-factory.h>
#include <gtest/gtest.h>

TEST_F(sensor_w1_factory_suite, basic)
{
    std::filesystem::path w1_fs_root = dirname;         // <--- using dirname from fixture, simulating /sys/bus/w1
    W1SensorFactory sensor_factory(w1_fs_root);

    W1Sensor* sensor = sensor_factory.find_by_address(0x02131d959eaa);
    ASSERT_NE(sensor, nullptr);

    change_temperature(36.5);                           // <--- write "36500" into device's temperature file
    ASSERT_FLOAT_EQ(sensor->get_temperature(), 36.5);   // <--- W1Sensor picks up new value

    change_temperature(42.324);                         // <--- temperature changes again
    ASSERT_FLOAT_EQ(sensor->get_temperature(), 42.324); // <--- sensor return new value

    delete sensor;                                      // <--- smart pointer not yet on the horizon, sigh
}
