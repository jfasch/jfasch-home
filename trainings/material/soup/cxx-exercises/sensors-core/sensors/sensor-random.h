#pragma once

#include "sensor.h"

#include <random>


class RandomSensor : public Sensor
{
public:
    RandomSensor(double low, double high);

    double low() const { return _low; }
    double high() const { return _high; }

    virtual double get_temperature();

private:
    std::uniform_real_distribution<double> _distribution;
    std::default_random_engine _engine;

    double _low;
    double _high;
};
