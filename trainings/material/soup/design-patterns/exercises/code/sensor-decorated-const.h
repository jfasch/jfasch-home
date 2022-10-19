#pragma once

#include "sensor-decorated.h"
#include "sensor-const.h"


class DecoratedConstantSensor : public DecoratedSensor
{
public:
    DecoratedConstantSensor(const std::string& name, double temperature)
    : DecoratedSensor(name, std::make_unique<ConstantSensor>(temperature)),
      _temperature(temperature) {}

    virtual std::string description() const override;

private:
    double _temperature;
};
