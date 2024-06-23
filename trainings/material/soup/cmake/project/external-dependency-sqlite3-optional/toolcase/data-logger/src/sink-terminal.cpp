#include "sink-terminal.h"

#include <iostream>


void SinkTerminal::output(const Measurements& data)
{
    for (const auto& [name, value]: data)
        std::cout << name << " " << value << std::endl;
}
