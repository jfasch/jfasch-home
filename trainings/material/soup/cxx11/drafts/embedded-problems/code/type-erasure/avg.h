#pragma once

double average(auto& sensors)  // <--- abbreviated function template
{
    double sum = 0;
    unsigned long num = 0;
    for (auto& s: sensors) {
        ++num;
        sum += s.get_temperature();
    }
    return sum/num;
}
