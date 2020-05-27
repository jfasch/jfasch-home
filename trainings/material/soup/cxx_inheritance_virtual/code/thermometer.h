#ifndef __HAVE_THERMOMETER_H__
#define __HAVE_THERMOMETER_H__

// INTERFACE!!
class Thermometer
{
public:
    virtual ~Thermometer() {}
    virtual double get_temperature() const = 0;
};

class SPIThermometer : public Thermometer
{
public:
    SPIThermometer(unsigned mosi, unsigned miso, unsigned clk, unsigned cs);
    virtual double get_temperature() const;

private:
    unsigned _mosi, _miso, _clk, _cs;
};

class I2CThermometer : public Thermometer
{
public:
    I2CThermometer(unsigned sda, unsigned scl, unsigned addr);
    virtual double get_temperature() const;

private:
    unsigned _sda, _scl, _addr;
};

#endif
