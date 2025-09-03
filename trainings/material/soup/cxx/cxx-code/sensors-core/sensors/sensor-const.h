#pragma once

#include "sensor.h"

class ConstantSensor : public Sensor
{
public:
    ConstantSensor(double value);

    double value() const { return _value; }
    double get_temperature() override;

private:
    double _value;
};
