#include "sensor-i2c-factory-vendor2.h"

#include "sensor-i2c-vendor2.h"


I2CSensor* I2CSensorFactory_Vendor2::create(unsigned int bus, uint8_t address)
{
    return new I2CSensor_Vendor2(bus, address);
}
