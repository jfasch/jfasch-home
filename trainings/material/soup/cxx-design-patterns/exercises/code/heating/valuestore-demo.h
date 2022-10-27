#pragma once

#include "sensor-reader.h"

#include <string>
#include <map>
#include <iostream>


class DemoValueStore : public SensorReader::ValueStore
{
public:
    void set(const std::string& name, double value) override
    {
        std::cerr << "DEMO-STORE: setting " << name << " = " << value << std::endl;
    }
    
private:
    std::map<std::string/*name*/, double/*temperature*/> _store;
};

