#pragma once

#include "measurements.h"

#include <string>
#include <ctime>


class Sink
{
public:
    virtual ~Sink() {}
    virtual void output(const Measurements& data) = 0;
};
