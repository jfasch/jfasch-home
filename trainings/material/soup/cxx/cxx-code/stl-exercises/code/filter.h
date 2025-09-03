#pragma once

#include <vector>

std::vector<int> filter(const std::vector<int>& input, bool(*)(int));
