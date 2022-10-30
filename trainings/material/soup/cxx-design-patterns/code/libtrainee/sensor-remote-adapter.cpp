#include "sensor-remote-adapter.h"

#include <sstream>
#include <stdexcept>


std::string RemoteSensorAdapter::execute(const std::string& request)
{
    if (request == "get_temperature") {
        double value = _sensor->get_temperature();
        std::ostringstream buffer;
        buffer << value;
        return buffer.str();
    }
    // ... more requests here maybe ...
    else
        throw std::runtime_error("invalid request");
}
