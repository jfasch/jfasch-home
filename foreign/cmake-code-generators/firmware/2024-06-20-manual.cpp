#include "conf-sensors.h"

#include <sensor-const.h>
#include <sensor-random.h>


SensorConfig conf_sensors;

namespace {

struct conf_sensors_init
{
    conf_sensors_init()
    {
        conf_sensors.add_sensor("bottom-left", std::make_unique<ConstantSensor>(37.5)); 
        conf_sensors.add_sensor("bottom-right", std::make_unique<ConstantSensor>(-273.15));
        conf_sensors.add_sensor("top-left", std::make_unique<RandomSensor>(0, 666));
        conf_sensors.add_sensor("top-right", std::make_unique<RandomSensor>(-273.15, 0));
    };
};

conf_sensors_init init;
};
