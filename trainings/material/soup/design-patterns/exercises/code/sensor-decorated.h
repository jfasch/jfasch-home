#pragma once

#include "sensor.h"

#include <string>
#include <memory>


class DecoratedSensor : public Sensor
{
public:
    DecoratedSensor(const std::string& name, std::unique_ptr<Sensor> sensor)
    : _name(name),
      _sensor(std::move(sensor)) {}

    const std::string& name() const { return _name; }
    virtual std::string description() const = 0;

    virtual double get_temperature() override
    {
        return _sensor->get_temperature();
    }

private:
    std::string _name;
    std::unique_ptr<Sensor> _sensor;
};
