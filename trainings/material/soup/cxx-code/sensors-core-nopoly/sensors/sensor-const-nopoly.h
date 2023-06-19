#pragma once

class ConstantSensor_nopoly
{
public:
    ConstantSensor_nopoly(double value);

    double value() const { return _value; }
    double get_temperature();

private:
    double _value;
};
