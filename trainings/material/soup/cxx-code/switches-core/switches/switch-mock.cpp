#include "switch-mock.h"


MockSwitch::MockSwitch()
: _state(Switch::State::OFF)
{}
    
void MockSwitch::on()
{
    _state = Switch::State::ON;
}

void MockSwitch::off()
{
    _state = Switch::State::OFF;
}
