#include "sensor-decorated-const.h"

#include <sstream>
#include <iomanip>


std::string DecoratedConstantSensor::description() const
{
    std::ostringstream buffer;
    buffer << "ConstantSensor(" << _temperature << ')';
    return buffer.str();
}
