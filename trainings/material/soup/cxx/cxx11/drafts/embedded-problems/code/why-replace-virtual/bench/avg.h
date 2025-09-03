#pragma once

#include "sensors.h"

double average(auto& sensors)
{
    double sum = 0;
    unsigned long num = 0;
    for (auto& s: sensors) {
        ++num;
        sum += s->get_temperature();
    }
    return sum/num;
}
