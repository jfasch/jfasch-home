#pragma once

#include "display.h"
#include <iostream>


class ConsoleDisplay : public Display
{
public:
    ConsoleDisplay(int num_chars, 
                   char mark, 
                   char space, 
                   double min, 
                   double max, 
                   double center,
                   std::ostream& o = std::cout);

    ~ConsoleDisplay() override;

    void show_temperature(double temperature) override;

private:
    int _temp_bucket(double temperature);

private:
    int _num_chars;
    char _mark;
    char _space;
    double _min;
    double _max;
    double _center;
    std::ostream& _o;

    char* _buffer;
    int _center_bucket;
};
