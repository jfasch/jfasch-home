#pragma once

#include <sensor.h>

#include <string>
#include <memory>


class DecoratedSensor : public Sensor
{
public:
    DecoratedSensor(const std::string& name)
    : _name(name) {}

    const std::string& name() const { return _name; }
    virtual std::string description() const = 0;

private:
    std::string _name;
};
