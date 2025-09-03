#pragma once

#include "source.h"


class SourceMovable : public Source
{
public:
    SourceMovable(const char* resource);
    SourceMovable(SourceMovable&&);
    SourceMovable& operator=(SourceMovable&&);
    ~SourceMovable();

    const char* resource() const { return _resource; }
    const char* get() override;

private:
    char* _resource;
};
