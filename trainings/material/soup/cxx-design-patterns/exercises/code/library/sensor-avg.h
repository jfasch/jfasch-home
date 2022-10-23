#pragma once

#include "sensor.h"

#include <vector>
#include <memory>


class AveragingSensor : public Sensor
{
public:
    AveragingSensor() = default;
    AveragingSensor(const std::initializer_list<Sensor*>&);

    void add(Sensor*);
    virtual double get_temperature() override;

private:
    std::vector<Sensor*> _sensors;
};
