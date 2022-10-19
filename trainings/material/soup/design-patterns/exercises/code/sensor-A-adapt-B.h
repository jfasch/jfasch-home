#pragma once

#include "sensor-A.h"
#include "sensor.h"

#include <memory>


class SensorB_Adapter : public SensorA
{
public:
    SensorB_Adapter(std::unique_ptr<Sensor> adaptee) : _adaptee(std::move(adaptee)) {}
    double get_temperature()
    {
        double celsius = _adaptee->get_temperature();
        return celsius * 5/9 + 32;
    }

private:
    std::unique_ptr<Sensor> _adaptee;
};
