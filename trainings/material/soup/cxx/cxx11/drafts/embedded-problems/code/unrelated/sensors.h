#pragma once

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

struct SensorPtr
{
    enum Type
    {
        SENSOR1,
        SENSOR2,
    };
    union variant
    {
        Sensor1* s1;
        Sensor2* s2;
    };
    SensorPtr(Sensor1* s) { type = SENSOR1; variant.s1 = s; }
    SensorPtr(Sensor2* s) { type = SENSOR2; variant.s2 = s; }
    Type type;
    variant variant;
};
