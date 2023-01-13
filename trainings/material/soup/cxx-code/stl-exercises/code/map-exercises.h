#pragma once

#include <map>
#include <string>

void map_insert_simple(std::map<std::string, int>&, const std::string&, int);
bool map_insert_check_duplicate(std::map<std::string, int>&, const std::string&, int);
bool map_remove_by_key(std::map<std::string, int>&, const std::string& key);
bool map_find(const std::map<std::string, int>&, const std::string& key, int& value);
