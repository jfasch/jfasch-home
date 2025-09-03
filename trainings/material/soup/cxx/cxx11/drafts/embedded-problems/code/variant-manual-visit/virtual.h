#pragma once

struct get_temperature_visitor
{
    double operator()(Sensor1& s) { return s.get_temperature(); }
    double operator()(Sensor2& s) { return s.get_temperature(); }
    // <--- take care to implement operator() for all types covered in union
};

static inline double get_temperature(Sensor& s)
{
    return std::visit(get_temperature_visitor(), s);
}
