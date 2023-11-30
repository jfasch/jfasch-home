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

union SensorUnion
{
    Sensor1* s1;
    Sensor2* s2;
};

enum class SensorType
{
    SENSOR1,
    SENSOR2,
};

struct SensorVariant
{
    SensorVariant(Sensor1* s) { type = SensorType::SENSOR1; sensor_union.s1 = s; }
    SensorVariant(Sensor2* s) { type = SensorType::SENSOR2; sensor_union.s2 = s; }

    SensorType type;
    SensorUnion sensor_union;
};

static inline double get_temperature(SensorVariant sv)
{
    switch (sv.type) {
        case SensorType::SENSOR1: {
            Sensor1* s1 = sv.sensor_union.s1;
            return s1->get_temperature();
        }
        case SensorType::SENSOR2: {
            Sensor2* s2 = sv.sensor_union.s2;
            return s2->get_temperature();
        }
    }
    return -273.15; // <--- never reached
}

}
