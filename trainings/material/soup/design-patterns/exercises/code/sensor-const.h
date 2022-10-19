#pragma once

#include "sensor.h"

class ConstantSensor : public Sensor
{
public:
    ConstantSensor(double temp)
    : _temp(temp) {}

    virtual double get_temperature()
    {
        return _temp;
    }

private:
    double _temp;
};
