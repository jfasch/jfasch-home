#pragma once

#include "display.h"

class NullDisplay : public Display
{
public:
    NullDisplay(double temperature = 0.0)
    : _temperature(temperature) {}

    void show_temperature(double) override;
    double current_temperature() const { return _temperature; }

private:
    double _temperature;
};
