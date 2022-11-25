#include "sensor-remote.h"

#include <cstdio>
#include <stdexcept>


double RemoteSensor::get_temperature()
{
    std::string response = _server->write("get_temperature");
    double value;
    int num_items = std::sscanf(response.c_str(), "%lf", &value);
    if (num_items != 1)
        throw std::runtime_error("invalid response");
    return value;
}
