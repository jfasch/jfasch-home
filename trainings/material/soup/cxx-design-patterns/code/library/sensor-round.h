#pragma once

#include "sensor.h"

#include <cmath>


class RoundingSensor : public Sensor
{
public:
    RoundingSensor(Sensor* sensor) : _sensor(sensor) {}

    virtual double get_temperature()
    {
        double value = _sensor->get_temperature();
        return std::round(value);
    }

private:
    Sensor* _sensor;
};
