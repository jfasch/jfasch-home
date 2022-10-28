#pragma once

#include "sensor-A.h"


class AConstantSensor : public ASensor
{
public:
    AConstantSensor(double value)
    : _value(value) {}

    double value() const { return _value; }

    virtual double get_temperature_fahrenheit()
    {
        return _value;
    }

private:
    double _value;
};
