#pragma once

#include "sensor.h"


class ConstantSensor : public Sensor
{
public:
    ConstantSensor(double value);
    double get_temperature() override;

    double value() const { return _value; }

private:
    double _value;
};
