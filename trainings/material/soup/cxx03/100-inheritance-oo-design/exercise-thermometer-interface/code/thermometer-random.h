#ifndef THERMOMETER_RANDOM_H
#define THERMOMETER_RANDOM_H

#include <random>

class ThermometerRandom
{
public:
    ThermometerRandom(double lo_range, double hi_range);
    virtual double get_temperature();

private:
    std::uniform_real_distribution<double> _distribution;
    std::default_random_engine _engine;
};

#endif
