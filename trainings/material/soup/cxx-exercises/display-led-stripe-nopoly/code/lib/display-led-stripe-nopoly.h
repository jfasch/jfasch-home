#pragma once

#include <switch-mock-nopoly.h>
#include <sensor-mock-nopoly.h>

#include <vector>


class LEDStripeDisplay_nopoly
{
public:
    LEDStripeDisplay_nopoly(
        double low, double high, 
        MockSensor_nopoly* sensor, 
        const std::vector<MockSwitch_nopoly*>& leds)
    : _low(low), _high(high), _sensor(sensor), _leds(leds) {}

    void check();

private:
    double _low;
    double _high;
    MockSensor_nopoly* _sensor;
    std::vector<MockSwitch_nopoly*> _leds;
};
