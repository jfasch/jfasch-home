#include "map-exercises.h"

void map_insert_simple(std::map<std::string, int>& map, const std::string& s, int i)
{
    map[s] = i;
}

bool map_insert_check_duplicate(std::map<std::string, int>& map, const std::string& s, int i)
{
    auto [iter, inserted] = map.insert(std::make_pair(s, i));
    return inserted;
}

bool map_remove_by_key(std::map<std::string, int>& map, const std::string& key)
{
    size_t nremoved = map.erase(key);
    return nremoved == 1;
}

bool map_find(const std::map<std::string, int>& map, const std::string& key, int& value)
{
    auto found = map.find(key);
    if (found == map.end())
        return false;
    value = found->second;
    return true;
}
