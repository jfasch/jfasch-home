#pragma once

#include <sensor-mock-nopoly.h>
#include <switch-mock-nopoly.h>

class Hysteresis_nopoly
{
public:
    Hysteresis_nopoly(MockSensor_nopoly* sensor, MockSwitch_nopoly* switcH, double low, double high);
    void check();

private:
    MockSensor_nopoly* _sensor;
    MockSwitch_nopoly* _switch;
    double _low;
    double _high;
};
