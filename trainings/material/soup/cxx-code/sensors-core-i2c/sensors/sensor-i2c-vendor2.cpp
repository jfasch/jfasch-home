#include "sensor-i2c-vendor2.h"


I2CSensor_Vendor2::I2CSensor_Vendor2(unsigned int bus, uint8_t address)
: I2CSensor(bus, address) {}

double I2CSensor_Vendor2::get_temperature()
{ 
    return 42;
}
