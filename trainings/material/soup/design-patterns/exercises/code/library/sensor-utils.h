#pragma once

#include "sensor.h"
#include <vector>
#include <numeric>

template <typename Iter>
double average(Iter begin, Iter end)
{
    double sum = 0;
    unsigned count = 0;
    while (begin != end) {
        sum += (*begin)->get_temperature();
        ++begin;
        ++count;
    }

    return sum/count;
}
