#include "switch-mock.h"


MockSwitch::MockSwitch()
: _state(State::OFF)
{}
    
void MockSwitch::on()
{
    _state = State::ON;
}

void MockSwitch::off()
{
    _state = State::OFF;
}
