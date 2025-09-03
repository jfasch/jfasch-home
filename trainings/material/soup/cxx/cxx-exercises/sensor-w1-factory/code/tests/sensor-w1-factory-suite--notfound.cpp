#include "sensor-w1-factory-fixture.h"
#include <sensor-w1.h>
#include <sensor-w1-factory.h>
#include <gtest/gtest.h>

TEST_F(sensor_w1_factory_suite, notfound)
{
    std::filesystem::path w1_fs_root = dirname;         // <--- using dirname from fixture, simulating /sys/bus/w1
    W1SensorFactory sensor_factory(w1_fs_root);

    W1Sensor* sensor = 
        sensor_factory.find_by_address(0x012345678901); // <--- that device does not exist under /sys/bus/w1 (err, dirname)
    ASSERT_EQ(sensor, nullptr);                         // <--- returns NULL in case address is not found

    delete sensor;                                      // <--- smart pointer not yet on the horizon, sigh
}
