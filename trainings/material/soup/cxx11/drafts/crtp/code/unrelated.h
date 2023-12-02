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

struct SensorVariant
{
    enum Type
    {
        SENSOR1,
        SENSOR2,
    };
    union Sensor
    {
        Sensor1* s1;
        Sensor2* s2;
    };
    SensorVariant(Sensor1* s) { type = SENSOR1; sensor.s1 = s; }
    SensorVariant(Sensor2* s) { type = SENSOR2; sensor.s2 = s; }
    Type type;
    Sensor sensor;
};

static inline double get_temperature(SensorVariant sv)
{
    switch (sv.type) {
        case SensorVariant::Type::SENSOR1: {
            Sensor1* s1 = sv.sensor.s1;
            return s1->get_temperature();
        }
        case SensorVariant::Type::SENSOR2: {
            Sensor2* s2 = sv.sensor.s2;
            return s2->get_temperature();
        }
    }
    return -273.15; // <--- never reached
}

}
