#pragma once

#include "sensor-decorated.h"
#include "sensor-const.h"


class DecoratedConstantSensor : public DecoratedSensor
{
public:
    DecoratedConstantSensor(const std::string& name, double temperature)
    : DecoratedSensor(name),
      _sensor(temperature) {}

    virtual std::string description() const override;
    virtual double get_temperature() { return _sensor.get_temperature(); }

private:
    ConstantSensor _sensor;
};
