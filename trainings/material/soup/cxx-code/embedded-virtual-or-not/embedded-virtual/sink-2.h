#pragma once

#include "sink.h"
#include <iostream>

class Sink2 : public Sink
{
public:
    void put(const std::string& s) override
    {
        std::cout << "Sink2: " << s << std::endl;
    }
};
