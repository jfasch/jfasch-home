#pragma once

#include "sensor-w1.h"
#include <filesystem>


class W1SensorFactory
{
public:
    W1SensorFactory(const std::filesystem::path& w1_fs_root)
    : _w1_fs_root(w1_fs_root) {}

    W1Sensor* find_by_address(uint64_t) const;

private:
    const std::filesystem::path _w1_fs_root;
};
