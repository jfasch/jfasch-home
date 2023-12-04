#pragma once

static inline double get_temperature(Sensor& s)
{
    if (Sensor1* s1 = std::get_if<Sensor1>(&s))
        return s1->get_temperature();
    if (Sensor2* s1 = std::get_if<Sensor2>(&s))
        return s1->get_temperature();

    return -273.15;                                    // <--- take care to never get here
}
