#pragma once

#include "sensor.h"
#include "switch.h"
#include "hysteresis.h"


class BoilingPot
{
public:
    BoilingPot(Sensor* sensor, Switch* switcH);
    void heat(double set_temperature);
    void check();
    
private:
    Sensor* _sensor;
    Switch* _switch;
    Hysteresis _hysteresis;
    double _set_temperature;

};
