#pragma once

#include "sensor.h"
#include "switch.h"
#include "hysteresis.h"

#include <memory>


class BoilingPot
{
public:
    BoilingPot(std::unique_ptr<Sensor>&& sensor, std::unique_ptr<Switch>&& switcH);
    void heat(double set_temperature);
    void check();
    
private:
    Hysteresis _hysteresis;
    double _set_temperature;

};
