#pragma once

#include "sink.h"


class SinkTerminal : public Sink
{
public:
    void output(const Measurements& data) override;
};
