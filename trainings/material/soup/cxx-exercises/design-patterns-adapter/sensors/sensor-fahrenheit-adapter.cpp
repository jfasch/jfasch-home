#include "sensor-fahrenheit-adapter.h"
#include <sensor.h>

#include <memory>


FahrenheitSensor_Adapter::FahrenheitSensor_Adapter(FahrenheitSensor* adaptee)
: _adaptee(adaptee) {}

double FahrenheitSensor_Adapter::get_temperature()
{
    double fahrenheit = _adaptee->get_temperature_f();
    return (fahrenheit -32) * 5/9;
}
