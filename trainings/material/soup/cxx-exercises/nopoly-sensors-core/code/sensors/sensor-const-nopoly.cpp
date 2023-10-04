#include "sensor-const-nopoly.h"

ConstantSensor_nopoly::ConstantSensor_nopoly(double value)
: _value(value) {}

double ConstantSensor_nopoly::get_temperature()
{
    return _value;
}
