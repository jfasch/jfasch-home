#pragma once

namespace related_no_virtual
{

enum class DerivedType
{
    SENSOR1,
    SENSOR2,
};

class Sensor
{
public:
    Sensor(DerivedType type) : type{type} {}
    const DerivedType type;
};

class Sensor1 : public Sensor
{
public:
    Sensor1(double temperature)
    : Sensor{DerivedType::SENSOR1},
      _temperature{temperature} {}

    double get_temperature() { return _temperature; }

private:
    double _temperature;
};

class Sensor2 : public Sensor
{
public:
    Sensor2(double temperature)
    : Sensor{DerivedType::SENSOR2},
      _temperature{temperature} {}

    double get_temperature() { return _temperature; }

private:
    double _temperature;
};

}
