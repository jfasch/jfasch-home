#pragma once

#include "source.h"

class SourceCopyable : public Source
{
public:
    SourceCopyable(const std::string& resource);

    const std::string& resource() const { return _resource; }
    const char* get() override;

private:
    std::string _resource;
};
