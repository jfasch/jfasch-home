#pragma once

#include "sensor.h"


class ConstantSensor : public Sensor
{
public:
    ConstantSensor(double value)
    : _value(value) {}

    double value() const { return _value; }

    virtual double get_temperature()
    {
        return _value;
    }

private:
    double _value;
};
