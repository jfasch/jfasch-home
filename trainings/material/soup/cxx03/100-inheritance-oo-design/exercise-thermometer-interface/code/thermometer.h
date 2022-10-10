#ifndef THERMOMETER_H
#define THERMOMETER_H

class Thermometer
{
public:
    virtual ~Thermometer() {}
    virtual double get_temperature() = 0;
};

#endif
