#pragma once

#include <string>

class FileSensor
{
public:
    FileSensor(const std::string& filename) : _filename{filename} {}
    double get_value() const;

private:
    std::string _filename;
};
