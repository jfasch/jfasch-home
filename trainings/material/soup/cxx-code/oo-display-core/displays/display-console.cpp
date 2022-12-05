#include "display-console.h"

#include <iostream>


void ConsoleDisplay::show_temperature(double temperature)
{
    unsigned num_chars_shown;

    if (temperature <= _min)
        num_chars_shown = 0;
    else if (temperature >= _max)
        num_chars_shown = _num_chars;
    else {
        double start = _min;
        double interval = (_max - _min) / _num_chars;
        for (unsigned char_num = 0; char_num <= _num_chars; char_num++) {
            double upper = start + char_num*interval;
            if (temperature <= upper) {
                num_chars_shown = char_num;
                break;
            }
        }
    }

    for (unsigned i=0; i<num_chars_shown; i++)
        _o << _c;
}
