#pragma once

#include "sensor-reader.h"

#include <string>
#include <cassert>


class DBusLogger : public SensorReader::Logger
{
public:
    void log(const std::string& msg) override
    {
        assert(!"Boss, we need a DBus consultant!!");
    }
};
