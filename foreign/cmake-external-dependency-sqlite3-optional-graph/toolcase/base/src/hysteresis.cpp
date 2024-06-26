#include "hysteresis.h"



Hysteresis::Hysteresis(
    std::unique_ptr<Sensor>&& sensor, 
    std::unique_ptr<Switch>&& switcH, 
    double low, 
    double high)
: _sensor(std::move(sensor)),
  _switch(std::move(switcH)),
  _low(low),
  _high(high)
{}

void Hysteresis::check()
{
    double current_temperature = _sensor->get_temperature();
    if (current_temperature < _low)
        _switch->set_state(true); 
    else if (current_temperature > _high)
        _switch->set_state(false); 
    else { /* leave as-is */ }
}

void Hysteresis::set_range(double low, double high)
{
    _low = low;
    _high = high;
}
