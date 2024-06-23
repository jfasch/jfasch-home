#include "measurements.h"


void Measurements::add_measurement(const std::string& name, double measurement)
{
    _data.insert({name, measurement});
}

double Measurements::get_measurement(const std::string& name)
{
    return _data[name];
}
