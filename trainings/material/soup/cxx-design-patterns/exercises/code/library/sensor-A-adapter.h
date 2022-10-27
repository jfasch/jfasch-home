#pragma once

#include "sensor-A.h"
#include "sensor.h"

#include <memory>


class ASensor_Adapter : public Sensor
{
public:
    ASensor_Adapter(ASensor* adaptee) : _adaptee(adaptee) {}
    double get_temperature()
    {
        double fahrenheit = _adaptee->get_temperature_fahrenheit();
        return (fahrenheit -32) * 5/9;
    }

private:
    ASensor* _adaptee;
};
