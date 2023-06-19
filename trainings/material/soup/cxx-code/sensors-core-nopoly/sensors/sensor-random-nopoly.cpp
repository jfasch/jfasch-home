#include "sensor-random-nopoly.h"


RandomSensor_nopoly::RandomSensor_nopoly(double low, double high)
: _distribution(std::uniform_real_distribution<double>(low, high)),
  _engine(std::random_device()()),
  _low(low),
  _high(high) {}

double RandomSensor_nopoly::get_temperature() 
{
    return _distribution(_engine);
}
