#pragma once

#include "sensor-decorated.h"
#include "sensor-random.h"


class DecoratedRandomSensor : public DecoratedSensor
{
public:
    DecoratedRandomSensor(const std::string& name, double low, double high)
    : DecoratedSensor(name, std::make_unique<RandomSensor>(low, high)),
      _low(low),
      _high(high) {}

    virtual std::string description() const override;

private:
    double _low;
    double _high;
};
