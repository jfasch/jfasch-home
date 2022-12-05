#pragma once

#include "display.h"
#include <iostream>


class ConsoleDisplay : public Display
{
public:
    ConsoleDisplay(unsigned num_chars, char c, double min, double max, std::ostream& o = std::cout)
    : _num_chars(num_chars), _c(c), _min(min), _max(max), _o(o) {}

    void show_temperature(double temperature) override;

private:
    unsigned _num_chars;
    char _c;
    double _min;
    double _max;
    std::ostream& _o;
};
