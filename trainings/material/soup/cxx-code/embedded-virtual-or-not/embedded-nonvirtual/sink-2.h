#pragma once

#include <string>
#include <iostream>


class Sink2
{
public:
    void put(const std::string& s)
    {
        std::cout << "Sink2: " << s << std::endl;
    }
};
