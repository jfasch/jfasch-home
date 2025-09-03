#include "thermometer.h"

#include <stdlib.h>
#include <time.h>


// -----------------------------------------------------------
SPIThermometer::SPIThermometer(unsigned mosi, unsigned miso, unsigned clk, unsigned cs)
: _mosi(mosi), _miso(miso), _clk(clk), _cs(cs)
{
    srand(time(nullptr));
}

double SPIThermometer::get_temperature() const
{
    int num = rand(); // milli-degrees
    return ((double)num/RAND_MAX) * 1000;
}

// -----------------------------------------------------------
I2CThermometer::I2CThermometer(unsigned sda, unsigned scl, unsigned addr)
: _sda(sda), _scl(scl), _addr(addr)
{
    srand(time(nullptr));
}

double I2CThermometer::get_temperature() const
{
    int num = rand(); // milli-degrees
    return ((double)num/RAND_MAX) * 1000;
}
