#pragma once

#include <string>


class Source
{
public:
    virtual ~Source() = default;
    virtual std::string get() = 0;
};
