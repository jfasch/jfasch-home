#pragma once

namespace classic_virtual
{

class Sensor
{
public:
    virtual ~Sensor() = default;
    virtual double get_temperature() = 0;
};

class Sensor1 : public Sensor
{
public:
    Sensor1(double temperature)
    : _temperature{temperature} {}

    double get_temperature() override { return _temperature; }

private:
    double _temperature;
};

class Sensor2 : public Sensor
{
public:
    Sensor2(double temperature)
    : _temperature{temperature} {}

    double get_temperature() override { return _temperature; }

private:
    double _temperature;
};

}
