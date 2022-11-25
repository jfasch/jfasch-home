#pragma once

#include <sensor-fahrenheit.h>
#include <sensor.h>

#include <memory>


class FahrenheitSensor_Adapter : public Sensor
{
public:
    FahrenheitSensor_Adapter(FahrenheitSensor* adaptee);
    double get_temperature();

private:
    FahrenheitSensor* _adaptee;
};
