#pragma once

#include <vector>
#include <optional>

struct BigData
{
    BigData(std::initializer_list<double> numbers) : numbers{numbers} {}
    std::vector<double> numbers;
};

std::optional<double> crunch(BigData*);
