#pragma once

#include <cstring>

class BigData
{
public:
    BigData(unsigned size, char content) : _data(new char[size])
    {
        memset(_data, content, size);
    }
    ~BigData()
    {
        delete[] _data;
    }

    char at(unsigned i) const { return _data[i]; }

private:
    char* _data;
};
