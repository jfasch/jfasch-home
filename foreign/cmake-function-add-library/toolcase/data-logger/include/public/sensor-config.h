#pragma once

#include "sensor.h"
#include "measurements.h"

#include <string>
#include <map>
#include <memory>


class SensorConfig
{
public:
    void add_sensor(const std::string& name, std::unique_ptr<Sensor>&& sensor);
    Measurements take_measurements() const;
    
private:
    std::map<std::string, std::unique_ptr<Sensor>> _sensors;
};

