#pragma once

#include "fixture-tmpdir.h"
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
