#pragma once

class Sensor
{
public:
    virtual ~Sensor() = default;

    // returns degrees Celsius
    virtual double get_temperature() = 0;
};
