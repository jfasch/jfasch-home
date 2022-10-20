#pragma once

#include "sensor-decorated.h"
#include "sensor-random.h"


class DecoratedRandomSensor : public DecoratedSensor
{
public:
    DecoratedRandomSensor(const std::string& name, double low, double high)
    : DecoratedSensor(name),
      _sensor(low, high) {}

    virtual std::string description() const override;
    virtual double get_temperature() { return _sensor.get_temperature(); }

private:
    RandomSensor _sensor;
};
