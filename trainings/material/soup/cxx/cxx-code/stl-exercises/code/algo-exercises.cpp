#include "algo-exercises.h"

#include <algorithm>

void copy_into_vector(const char** src, unsigned int n, std::vector<std::string>& dst)
{
    dst.resize(n);
    std::copy(src, src+n, dst.begin());
}

bool find_in_vector(const std::vector<std::string>& vec, const std::string& s)
{
    auto found = std::find(vec.begin(), vec.end(), s);
    return found != vec.end();
}
