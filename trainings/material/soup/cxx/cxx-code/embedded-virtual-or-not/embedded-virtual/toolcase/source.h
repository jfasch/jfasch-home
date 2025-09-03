#pragma once

#include <string>


class Source
{
public:
    virtual ~Source() = default;
    virtual const char* get() = 0;
};
