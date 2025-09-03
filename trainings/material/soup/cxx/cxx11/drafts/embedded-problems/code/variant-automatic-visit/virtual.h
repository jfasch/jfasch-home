#pragma once

struct get_temperature_visitor
{
    double operator()(auto& s)                         // <--- abbreviated function template
    { 
        return s.get_temperature();
    }
};

static inline double get_temperature(Sensor& s)
{
    return std::visit(get_temperature_visitor(), s);
}
