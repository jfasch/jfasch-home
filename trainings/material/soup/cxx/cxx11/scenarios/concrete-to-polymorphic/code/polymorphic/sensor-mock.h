#pragma once

#include "sensor.h"

class MockSensor : public Sensor                       // <-- is-a Sensor
{
public:
    MockSensor(double initial_value) : _value{initial_value} {}
    double get_value() const override { return _value; }

    // for tests only
    void set_value(double v) { _value = v; }
private:
    double _value;
};
