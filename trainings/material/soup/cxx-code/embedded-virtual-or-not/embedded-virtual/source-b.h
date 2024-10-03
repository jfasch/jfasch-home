#pragma once

#include "source.h"

class SourceB : public Source
{
public:
    std::string get() override
    {
        return "Source B";
    }
};
