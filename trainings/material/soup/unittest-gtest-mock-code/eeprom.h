#ifndef __HAVE_EEPROM_H__
#define __HAVE_EEPROM_H__

#include <cstdint>


class EEPROM
{
public:
    virtual ~EEPROM() {}

    virtual void write(uint32_t offset, const void* data, uint32_t size) = 0;
    virtual void read(uint32_t offset, void* data, uint32_t size) const = 0;
};

#endif
