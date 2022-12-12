#include <gtest/gtest.h>

#include <sensor-w1.h>
#include <sensor-w1-factory.h>
#include <fixture-tmpdir.h>
#include <filesystem>
#include <fstream>

struct sensor_w1_factory_suite : public tmpdir_fixture
{
    sensor_w1_factory_suite()
    {
        std::filesystem::path device_dir = dirname / "devices" / "28-02131d959eaa";
        std::filesystem::create_directories(device_dir);
        std::ofstream(device_dir / "temperature") << "42459" << std::flush;
    }

    void change_temperature(double temperature)
    {
        unsigned temp_milli = temperature * 1000;
        std::ofstream(dirname / "devices" / "28-02131d959eaa" / "temperature") << temp_milli << std::flush;
    }
};

TEST_F(sensor_w1_factory_suite, basic)
{
    std::filesystem::path w1_fs_root = dirname;
    W1SensorFactory sensor_factory(w1_fs_root);

    W1Sensor* sensor = sensor_factory.find_by_address(0x02131d959eaa);
    ASSERT_NE(sensor, nullptr);

    change_temperature(36.5);

    ASSERT_FLOAT_EQ(sensor->get_temperature(), 36.5);
}

TEST_F(sensor_w1_factory_suite, notfound)
{
    std::filesystem::path w1_fs_root = dirname;
    W1SensorFactory sensor_factory(w1_fs_root);

    W1Sensor* sensor = sensor_factory.find_by_address(0x012345678901);
    ASSERT_EQ(sensor, nullptr);

    change_temperature(36.5);

    ASSERT_FLOAT_EQ(sensor->get_temperature(), 36.5);
}

TEST_F(sensor_w1_factory_suite, find_is_const)
{
    std::filesystem::path w1_fs_root = dirname;
    const W1SensorFactory sensor_factory(w1_fs_root);       // <--- *const*
    sensor_factory.find_by_address(0x02131d959eaa);
}
