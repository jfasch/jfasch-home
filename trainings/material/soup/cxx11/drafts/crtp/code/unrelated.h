#pragma once

namespace unrelated
{

class Sensor1
{
public:
    Sensor1(double temperature)
    : _temperature{temperature} {}

    double get_temperature() { return _temperature; }

private:
    double _temperature;
};

class Sensor2
{
public:
    Sensor2(double temperature)
    : _temperature{temperature} {}

    double get_temperature() { return _temperature; }

private:
    double _temperature;
};

template <typename T>
double get_temperature(T* s)
{
    return s->get_temperature();
}

}
