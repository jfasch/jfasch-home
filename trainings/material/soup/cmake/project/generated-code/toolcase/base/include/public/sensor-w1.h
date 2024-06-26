#pragma once

#include "sensor.h"

#include <string>


class W1Sensor : public Sensor
{
public:
    W1Sensor(const std::string& filename);
    double get_temperature() override;

private:
    std::string _filename;
};



