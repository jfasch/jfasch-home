#ifndef THERMOMETER_CONST_H
#define THERMOMETER_CONST_H

class ThermometerConst
{
public:
    ThermometerConst(double temperature);
    virtual double get_temperature();

private:
    double _temperature;
};

#endif
