#pragma once

class Sensor
{
public:
    virtual ~Sensor() = default;                       // <-- dogmatic!
    virtual double get_value() const = 0;              // <-- dynamic dispatch
};
