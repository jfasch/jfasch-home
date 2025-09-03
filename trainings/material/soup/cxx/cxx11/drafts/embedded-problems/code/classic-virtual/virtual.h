#pragma once

static inline double get_temperature(Sensor* s)
{
    return s->get_temperature();
}
