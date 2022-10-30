#pragma once

class ASensor
{
public:
    virtual ~ASensor() {}
    virtual double get_temperature_fahrenheit() = 0;
};
