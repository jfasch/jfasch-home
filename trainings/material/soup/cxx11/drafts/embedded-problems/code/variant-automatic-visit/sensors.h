#pragma once

#include <variant>

class Sensor1
{
public:
    Sensor1(double temperature) : _temperature{temperature} {}
    double get_temperature() { return _temperature; }

    Sensor1() = delete;
    Sensor1(const Sensor1&) = delete;
    Sensor1& operator=(const Sensor1&) = delete;
    Sensor1(Sensor1&&) = default;
    Sensor1& operator=(Sensor1&&) = default;
private:
    double _temperature;
};

class Sensor2
{
public:
    Sensor2(double temperature) : _temperature{temperature} {}
    double get_temperature() { return _temperature; }

    Sensor2() = delete;
    Sensor2(const Sensor2&) = delete;
    Sensor2& operator=(const Sensor2&) = delete;
    Sensor2(Sensor2&&) = default;
    Sensor2& operator=(Sensor2&&) = default;
private:
    double _temperature;
};

using Sensor = std::variant<Sensor1, Sensor2>;
