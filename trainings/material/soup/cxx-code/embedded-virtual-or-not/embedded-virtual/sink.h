#pragma once

#include <string>

class Sink
{
public:
    virtual ~Sink() = default;
    virtual void put(const std::string&) = 0;
};
