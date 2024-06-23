#include "boiling-pot.h"
#include <hysteresis.h>

BoilingPot::BoilingPot(
    std::unique_ptr<Sensor>&& sensor, 
    std::unique_ptr<Switch>&& switcH) 
: _hysteresis(std::move(sensor), std::move(switcH), 0, 0) {}


void BoilingPot::heat(double set_temperature)
{
    _hysteresis.set_range(set_temperature-1, set_temperature+1);
}

void BoilingPot::check()
{
    _hysteresis.check();
}


 
