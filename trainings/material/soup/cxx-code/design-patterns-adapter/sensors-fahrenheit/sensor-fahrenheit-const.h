#pragma once

#include "sensor-fahrenheit.h"


class ConstantFahrenheitSensor : public FahrenheitSensor
{
public:
    ConstantFahrenheitSensor(double value);

    virtual double get_temperature_f();
    double value() const { return _value; }

private:
    double _value;
};
