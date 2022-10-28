#include "sensor-i2c-factory-vendor1.h"

#include "sensor-i2c-vendor1.h"


I2CSensor* I2CSensorFactory_Vendor1::create(unsigned int bus, uint8_t address)
{
    return new I2CSensor_Vendor1(bus, address);
}
