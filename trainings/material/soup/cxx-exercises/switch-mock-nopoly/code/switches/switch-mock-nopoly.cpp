#include "switch-mock-nopoly.h"


MockSwitch_nopoly::MockSwitch_nopoly(State initial_state)
: _state(initial_state)
{}
    
void MockSwitch_nopoly::on()
{
    _state = State::ON;
}

void MockSwitch_nopoly::off()
{
    _state = State::OFF;
}
