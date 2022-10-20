#include "sensor-decorated-const.h"

#include <sstream>
#include <iomanip>


std::string DecoratedConstantSensor::description() const
{
    std::ostringstream buffer;
    buffer << "ConstantSensor(" << _sensor.value() << ')';
    return buffer.str();
}
