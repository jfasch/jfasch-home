#pragma once

#include <string>
#include <map>


class Measurements
{
public:
    void add_measurement(const std::string& name, double measurement);
    double get_measurement(const std::string& name);

    auto begin() const       { return _data.begin(); }
    auto end() const         { return _data.end(); }

private:
    std::map<std::string, double> _data;
};
