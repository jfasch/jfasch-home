#include "namevaluestore.h"

using std::string;


NameValueStore::NameValueStore(EEPROM* eeprom)
: eeprom_(eeprom) {}

void NameValueStore::set(
    const std::string& name,
    const std::string& value)
{
}

std::string NameValueStore::get(
    const std::string& name)
{
    return string();
}
