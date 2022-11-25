#pragma once

class FahrenheitSensor
{
public:
    virtual ~FahrenheitSensor() {}
    virtual double get_temperature_f() = 0;
};
