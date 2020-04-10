#ifndef __HAVE_THERMOMETER_H__
#define __HAVE_THERMOMETER_H__

#include <iostream>
using namespace std;


class SPIThermometer
{
public:
    SPIThermometer(unsigned miso, unsigned mosi, unsigned clk, unsigned cs);

    double get_temperature() const;

    SPIThermometer(const SPIThermometer&) = delete;
    SPIThermometer& operator=(const SPIThermometer&) = delete;

private:
    unsigned _miso;
    unsigned _mosi;
    unsigned _clk;
    unsigned _cs;
};

class I2CThermometer
{
public:
    I2CThermometer(unsigned sda, unsigned scl, unsigned addr);
    double get_temperature() const;

    I2CThermometer(const I2CThermometer&) = delete;
    I2CThermometer& operator=(const I2CThermometer&) = delete;

private:
    unsigned _sda;
    unsigned _scl;
    unsigned _addr;
};

#endif
