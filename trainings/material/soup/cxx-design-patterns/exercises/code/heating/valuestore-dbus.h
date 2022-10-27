#pragma once

#include "sensor-reader.h"

#include <string>
#include <map>


class DBusValueStore : public SensorReader::ValueStore
{
public:
    void set(const std::string& name, double value) override
    {
        assert(!"Boss, we need a DBus consultant!!");
    }
};

