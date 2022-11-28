#include "sensor-w1.h"

#include <stdexcept>
#include <cstring>

#include <unistd.h>
#include <fcntl.h>

using namespace std;


W1Sensor::W1Sensor(const std::string& filename)
: _filename(filename) {}

double W1Sensor::get_temperature()
{
    int fd = open(_filename.c_str(), O_RDONLY);
    if (fd == -1) {
        string msg = "cannot open temperature file " + _filename;
        throw runtime_error(msg.c_str());
    }

    char tmp[32];
    memset(tmp, 0, sizeof(tmp));
    ssize_t nread = ::read(fd, tmp, sizeof(tmp)-1);

    ::close(fd);

    if (nread == -1) {
        string msg = "cannot read temperature file " + _filename;
        throw runtime_error(msg);
    }

    return stod(tmp) / 1000;
}
