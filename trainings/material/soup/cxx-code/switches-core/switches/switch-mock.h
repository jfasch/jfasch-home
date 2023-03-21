#pragma once

#include "switch.h"


class MockSwitch : public Switch
{
public:
    MockSwitch();
    
    Switch::State state() const override { return _state; }
    void on() override;
    void off() override;

private:
    Switch::State _state;
};
