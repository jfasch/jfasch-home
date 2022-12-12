#include "sensor-w1-factory-fixture.h"
#include <sensor-w1.h>
#include <sensor-w1-factory.h>
#include <gtest/gtest.h>

TEST_F(sensor_w1_factory_suite, find_is_const)
{
    std::filesystem::path w1_fs_root = dirname;
    const W1SensorFactory sensor_factory(w1_fs_root);   // <--- *const*
    sensor_factory.find_by_address(0x02131d959eaa);     // <--- if that compiles, then the test passes
}
