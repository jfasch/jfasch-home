#include "sensor-avg.h"


AveragingSensor::AveragingSensor(const std::initializer_list<Sensor*>& init)
: _sensors(init) {}

void AveragingSensor::add(Sensor* sensor)
{
    _sensors.push_back(sensor);
}

double AveragingSensor::get_temperature()
{
    double sum = 0;
    int count = 0;

    for (auto s: _sensors) {
        sum += s->get_temperature();
        count++;
    }

    return sum/count;
}
