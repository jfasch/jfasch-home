#pragma once

class MockSensor
{
public:
    MockSensor(double initial_value) : _value{initial_value} {}
    double get_value() const { return _value; }
    // for tests only
    void set_value(double v) { _value = v; }
private:
    double _value;
};
