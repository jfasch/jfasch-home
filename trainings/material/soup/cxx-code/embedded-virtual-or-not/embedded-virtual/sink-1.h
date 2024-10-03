#pragma once

#include "sink.h"
#include <iostream>

class Sink1 : public Sink
{
public:
    void put(const std::string& s) override
    {
        std::cout << "Sink1: " << s << std::endl;
    }
};
