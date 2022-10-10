#include "thermometer-random.h"

ThermometerRandom::ThermometerRandom(double lo_range, double hi_range)
: _distribution(lo_range, hi_range),
  _engine(std::random_device()()) {}

double ThermometerRandom::get_temperature()
{
    double temperature = _distribution(_engine);
    return temperature;
}
