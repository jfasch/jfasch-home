#include "thermometer-const.h"

ThermometerConst::ThermometerConst(double temperature)
: _temperature(temperature) {}

double ThermometerConst::get_temperature()
{
    return _temperature;
}
