#pragma once

class SensorA
{
public:
    virtual ~SensorA() {}

    // returns degrees Fahrenheit
    virtual double get_temperature() = 0;
};
