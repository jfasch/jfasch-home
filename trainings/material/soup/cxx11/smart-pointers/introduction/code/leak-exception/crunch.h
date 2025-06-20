#pragma once

#include <vector>

struct BigData
{
    BigData(std::initializer_list<double> numbers) : numbers{numbers} {}
    std::vector<double> numbers;
};

double crunch(BigData*);
