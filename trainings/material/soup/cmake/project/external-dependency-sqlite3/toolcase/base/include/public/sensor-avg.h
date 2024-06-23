#pragma once

#include "sensor.h"

#include <vector>


class AveragingSensor : public Sensor
{
public:
    void add(Sensor*);
    double get_temperature() override;

private:
    std::vector<Sensor*> _sensors;
};
