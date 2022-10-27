#pragma once

#include "sensor-reader.h"

#include <string>
#include <iostream>


class DemoLogger : public SensorReader::Logger
{
public:
    void log(const std::string& msg) override
    {
        std::cerr << "DEMO-LOGGER: " << msg << std::endl;
    }
};
