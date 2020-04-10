#ifndef __HAVE_THERMOMETER_H__
#define __HAVE_THERMOMETER_H__

class SPIThermometer
{
public:
    SPIThermometer(unsigned mosi, unsigned miso, unsigned clk, unsigned cs);
    double get_temperature() const;

private:
    unsigned _mosi, _miso, _clk, _cs;
};

class I2CThermometer
{
public:
    I2CThermometer(unsigned sda, unsigned scl, unsigned addr);
    double get_temperature() const;

private:
    unsigned _sda, _scl, _addr;
};

#endif
