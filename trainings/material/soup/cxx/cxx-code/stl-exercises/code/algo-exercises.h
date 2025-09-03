#pragma once

#include <vector>
#include <string>

void copy_into_vector(const char** src, unsigned int n, std::vector<std::string>& dst);
bool find_in_vector(const std::vector<std::string>&, const std::string&);
