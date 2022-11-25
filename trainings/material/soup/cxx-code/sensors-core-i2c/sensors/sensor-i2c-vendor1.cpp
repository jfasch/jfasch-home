#include "sensor-i2c-vendor1.h"

I2CSensor_Vendor1::I2CSensor_Vendor1(unsigned int bus, uint8_t address)
: I2CSensor(bus, address) {}

double I2CSensor_Vendor1::get_temperature()
{ 
    return 42;
}
