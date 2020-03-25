#ifndef __HAVE_NAMEVALUESTORE_H__
#define __HAVE_NAMEVALUESTORE_H__

#include "eeprom.h"

#include <string>


class NameValueStore
{
public:
    NameValueStore(EEPROM*);

    void set(const std::string& name, const std::string& value);
    std::string get(const std::string& name);

private:
    EEPROM* eeprom_;
};

#endif
