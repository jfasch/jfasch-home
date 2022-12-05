#pragma once

class Display
{
public:
    virtual ~Display() {};
    virtual void show_temperature(double temperature) = 0;
};
