#ifndef CXX11_UNIQUE_PTR_SENSORS_H
#define CXX11_UNIQUE_PTR_SENSORS_H

#include <random>


class Sensor
{
public:
    virtual ~Sensor() {}
    virtual double get_temperature() = 0;
};

class RandomSensor : public Sensor
{
public:
    RandomSensor(double low, double high)
    : _distribution(std::uniform_real_distribution<double>(low, high)),
      _engine(std::random_device()()) {}

    virtual double get_temperature() 
    {
        return _distribution(_engine);
    }

private:
    std::uniform_real_distribution<double> _distribution;
    std::default_random_engine _engine;
};

class ConstantSensor : public Sensor
{
public:
    ConstantSensor(double temp)
    : _temp(temp) {}

    virtual double get_temperature()
    {
        return _temp;
    }

private:
    double _temp;
};

#endif
