#pragma once

#include "source.h"

class SourceA : public Source
{
public:
    std::string get() override
    {
        return "Source A";
    }
};
