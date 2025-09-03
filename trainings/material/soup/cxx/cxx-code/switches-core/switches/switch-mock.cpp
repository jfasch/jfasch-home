#include "switch-mock.h"


MockSwitch::MockSwitch(Switch::State initial_state)
: _state(initial_state)
{}
    
void MockSwitch::on()
{
    _state = Switch::State::ON;
}

void MockSwitch::off()
{
    _state = Switch::State::OFF;
}
