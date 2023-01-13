#include "vector-exercises.h"

void vector_append(std::vector<std::string>& vec, const std::string& s)
{
    vec.push_back(s);
}

std::string vector_join(const std::vector<std::string>& vec, char sep)
{
    auto begin = vec.begin();
    auto end = vec.end();

    std::string ret;

    while (begin != end) {
        ret += *begin;
        if (begin != end-1)
            ret += sep;
        ++begin;
    }

    return ret;
}
