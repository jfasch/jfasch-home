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

static inline double get_temperature(Sensor* s)
{
    switch (s->type) {
        case DerivedType::SENSOR1: {
            Sensor1* s1 = static_cast<Sensor1*>(s);
            return s1->get_temperature();
        }
        case DerivedType::SENSOR2: {
            Sensor2* s2 = static_cast<Sensor2*>(s);
            return s2->get_temperature();
        }
    }
    return -273.15; // <--- never reached
}

}
