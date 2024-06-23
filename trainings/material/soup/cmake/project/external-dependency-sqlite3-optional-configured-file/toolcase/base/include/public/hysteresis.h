#pragma once

#include "sensor.h"
#include "switch.h"

#include <memory>


class Hysteresis
{
public:
    Hysteresis(std::unique_ptr<Sensor>&& sensor, std::unique_ptr<Switch>&& switcH, double low, double high);
    void check();
    void set_range(double low, double high);

private:
    std::unique_ptr<Sensor> _sensor;
    std::unique_ptr<Switch> _switch;
    double _low;
    double _high;
};
