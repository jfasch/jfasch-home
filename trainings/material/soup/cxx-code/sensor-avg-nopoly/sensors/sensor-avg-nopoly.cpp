#include "sensor-avg-nopoly.h"

void AveragingSensor_nopoly::add(MockSensor_nopoly* sensor)
{
    _sensors.push_back(sensor);
}

double AveragingSensor_nopoly::get_temperature()
{
    double sum_temperatures = 0;
    for (MockSensor_nopoly* sensor: _sensors)
        sum_temperatures += sensor->get_temperature();
    return sum_temperatures / _sensors.size();
}
