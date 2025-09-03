#pragma once

#include "sensors.h"

static inline double get_temperature(Sensor* s)
{
    switch (s->type) {
        case DerivedType::SENSOR1: {
            Sensor1* s1 = static_cast<Sensor1*>(s);
            return s1->get_temperature();
        }
        case DerivedType::SENSOR2: {
            Sensor2* s2 = static_cast<Sensor2*>(s);
            return s2->get_temperature();
        }
    }
    return -273.15; // <--- never reached
}
