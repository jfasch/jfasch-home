#include "sensor-fahrenheit-const.h"


ConstantFahrenheitSensor::ConstantFahrenheitSensor(double value)
: _value(value) {}

double ConstantFahrenheitSensor::get_temperature_f()
{
    return _value;
}
