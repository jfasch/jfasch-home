#pragma once

#include "sink.h"
#include <iostream>

class SinkCopyable : public Sink
{
public:
    void put(const std::string& s) override
    {
        std::cout << "Sink1: " << s << std::endl;
    }
};
