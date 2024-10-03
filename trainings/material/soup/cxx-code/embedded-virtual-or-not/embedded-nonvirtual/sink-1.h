#pragma once

#include <string>
#include <iostream>


class Sink1
{
public:
    void put(const std::string& s)
    {
        std::cout << "Sink1: " << s << std::endl;
    }
};
