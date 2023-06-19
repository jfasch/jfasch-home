#pragma once


class MockSwitch_nopoly
{
public:
    enum State
    {
        ON,
        OFF
    };

    MockSwitch_nopoly(State initial_state);
    
    State state() const { return _state; }
    void on();
    void off();

private:
    State _state;
};
