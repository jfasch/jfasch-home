#pragma once

#include "hal-timer-oo.h"


namespace jf::hal
{

class OneshotTimer : public Timer
{
public:
    OneshotTimer(size_t milliseconds, User*);
    void start() override;

private:
    size_t _milliseconds;
};

}
