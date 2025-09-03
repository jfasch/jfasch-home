#pragma once

#include <optional>
#include <cstring>

struct BigData
{
    BigData(unsigned size, char content) : _data(new char[size])
    {
        memset(_data, content, size);
    }
    ~BigData()
    {
        delete[] _data;
    }
    char* _data;
};

std::optional<double> crunch(BigData*);
