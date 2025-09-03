#include "display-console.h"

#include <iostream>
#include <stdexcept>
#include <cassert>


ConsoleDisplay::ConsoleDisplay(int num_chars, 
                               char mark, 
                               char space, 
                               double min, 
                               double max, 
                               double center,
                               std::ostream& o)
: _num_chars(num_chars), 
  _mark(mark), 
  _space(space), 
  _min(min), 
  _max(max),
  _center(center),
  _o(o),
  _buffer(new char[num_chars])
{
    assert(num_chars >= 0);

    if (max < min)
        throw std::runtime_error("max<min");
    if (center < min || center > max)
        throw std::runtime_error("center not between min and max");

    _center_bucket = _temp_bucket(center);
    assert(_center_bucket >= 0);
    assert(_center_bucket < _num_chars);
}

ConsoleDisplay::~ConsoleDisplay()
{
    delete[] _buffer;
}

void ConsoleDisplay::show_temperature(double temperature)
{
    int temp_bucket = _temp_bucket(temperature);

    if (temp_bucket < 0) { // underflow 
        for (int i=0; i<_num_chars; i++)
            _buffer[i] = _space;
    }
    else if (temp_bucket >= _num_chars) { // overflow
        for (int i=0; i<_num_chars; i++)
            _buffer[i] = _mark;
    }
    else {
        if (temp_bucket <= _center_bucket) {
            for (int i=0; i<temp_bucket; i++)
                _buffer[i] = _space;
            for (int i=temp_bucket; i<=_center_bucket; i++)
                _buffer[i] = _mark;
            for (int i=_center_bucket+1; i<=_num_chars; i++)
                _buffer[i] = _space;
        }
        else {
            for (int i=0; i<_center_bucket; i++)
                _buffer[i] = _space;
            for (int i=_center_bucket; i<=temp_bucket; i++)
                _buffer[i] = _mark;
            for (int i=temp_bucket+1; i<_num_chars; i++)
                _buffer[i] = _space;
        }
    }

    for (int i=0; i<_num_chars; i++)
        _o << _buffer[i];
}

int ConsoleDisplay::_temp_bucket(double temperature)
{
    if (temperature < _min) return -1;    // underflow

    double area_width = (_max - _min) / _num_chars;
    for (int bucket=0; bucket<_num_chars; bucket++) {
        double area_start = _min + bucket * area_width;
        double area_end = area_start + area_width;

        if (temperature >= area_start && temperature < area_end)
            return bucket;
    }

    return _num_chars;     // overflow
}
