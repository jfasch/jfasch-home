#include "thermometer.h"

#include <cstdlib>
#include <ctime> 


// --------------------------------------------------------
SPIThermometer::SPIThermometer(unsigned miso, unsigned mosi, unsigned clk, unsigned cs)
: _miso(miso), _mosi(mosi), _clk(clk), _cs(cs)
{
    srand(time(nullptr));
}

double SPIThermometer::get_temperature() const
{
    cout << __PRETTY_FUNCTION__ << endl;
    int rtemp = rand();
    return (float)rtemp/1000/1000;
}

// --------------------------------------------------------
I2CThermometer::I2CThermometer(unsigned sda, unsigned scl, unsigned addr)
: _sda(sda), _scl(scl), _addr(addr)
{
    srand(time(nullptr));
}

double I2CThermometer::get_temperature() const
{
    cout << __PRETTY_FUNCTION__ << endl;
    int rtemp = rand();
    return (float)rtemp/1000/1000;
}
