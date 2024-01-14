#pragma once

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual double get_temperature() = 0;

    Sensor(unsigned int id) : _id(id) {}
    unsigned int id() const { return _id; }

private:
    unsigned int _id;
};
