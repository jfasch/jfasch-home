#include "sensor-decorated-random.h"

#include <sstream>
#include <iomanip>


std::string DecoratedRandomSensor::description() const
{
    std::ostringstream buffer;
    buffer << "RandomSensor(" << _low << ", " << _high << ')';
    return buffer.str();
}
