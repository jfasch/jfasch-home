#pragma once

class Sensor
{
public:
    virtual ~Sensor() {}

    // returns degrees Celsius
    virtual double get_temperature() = 0;
};
