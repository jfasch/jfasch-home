#include "sensor-decorated-random.h"

#include <sstream>
#include <iomanip>


std::string DecoratedRandomSensor::description() const
{
    std::ostringstream buffer;
    buffer << "RandomSensor(" << _sensor.low() << ", " << _sensor.high() << ')';
    return buffer.str();
}
