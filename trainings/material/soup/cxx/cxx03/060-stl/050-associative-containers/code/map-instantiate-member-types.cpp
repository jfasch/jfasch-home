#include <map>
#include <string>
#include <iostream>

using MyMap = std::map<int, std::string>;

int main()
{
    MyMap my_map;

    MyMap::key_type k{666};                                  // <--- same as "int k{666};"
    MyMap::mapped_type v{"sechshundersechsundsechzig"};      // <--- same as "std::string v{...};"
    MyMap::value_type kv{666, "sechshundersechsundsechzig"}; // <--- same as "std::pair<...>{666, ...};"

    // avoid "unused" warnings
    (void)k;
    (void)v;
    (void)kv;

    return 0;
}
