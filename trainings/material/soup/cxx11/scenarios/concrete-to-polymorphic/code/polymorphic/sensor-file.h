#pragma once

#include "sensor.h"
#include <string>

class FileSensor : public Sensor                       // <-- is-a Sensor
{
public:
    FileSensor(const std::string& filename) : _filename{filename} {}
    double get_value() const override;                 // <-- argh

private:
    std::string _filename;
};
