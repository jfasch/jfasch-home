#pragma once

#include "switch.h"

class SysFSGPIOSwitch : public Switch
{
public:
    SysFSGPIOSwitch(int gpioPin);
    ~SysFSGPIOSwitch();

    void set_state(bool state) override;
    bool get_state();

private:
    int pinNumber;
    void exportGPIO();
    void configureOutput();
    void unexportGPIO();
};
