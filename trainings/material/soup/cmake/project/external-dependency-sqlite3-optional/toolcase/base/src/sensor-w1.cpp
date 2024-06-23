#include "sensor-w1.h"

#include "file-util.h"

#include <string>
#include <cassert>
#include <fcntl.h>
#include <unistd.h>


W1Sensor::W1Sensor(const std::string& filename)
: _filename(filename) {}

double W1Sensor::get_temperature()
{ 
    std::string content = read_sysfs_file(_filename);

    long millis = std::stol(content);
    double temperature = (double)millis/1000;
    return temperature;
}


