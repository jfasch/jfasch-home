#pragma once


class Switch
{
public:
    enum class State
    {
        OFF,
        ON,
    };

public:
    virtual ~Switch() {}

    virtual void on() = 0;
    virtual void off() = 0;
    virtual State state() const = 0;
};
