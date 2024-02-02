#pragma once

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual double get_temperature() = 0;

    Sensor(unsigned int id) : _id(id) {}

    // unused, mostly
    unsigned int id() const { return _id; }

private:
    // unused, mostly
    unsigned int _id;
};
