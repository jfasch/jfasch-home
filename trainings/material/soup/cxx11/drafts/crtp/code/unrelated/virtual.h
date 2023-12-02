#pragma once

#include "sensors.h"

static inline double get_temperature(SensorPtr s)
{
    switch (s.type) {
        case SensorPtr::SENSOR1: {
            Sensor1* s1 = s.variant.s1;
            return s1->get_temperature();
        }
        case SensorPtr::SENSOR2: {
            Sensor2* s2 = s.variant.s2;
            return s2->get_temperature();
        }
    }
    return -273.15; // <--- never reached
}
