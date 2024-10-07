#include "source-movable.h"

#include <iostream>
#include <utility>
#include <cstring>


SourceMovable::SourceMovable(const char* resource)
: _resource(new char[strlen(resource)+1])
{
    strcpy(_resource, resource);
}

SourceMovable::SourceMovable(SourceMovable&& rhs)
: _resource(std::exchange(rhs._resource, nullptr)) {}

SourceMovable& SourceMovable::operator=(SourceMovable&& rhs)
{
    if (this != &rhs) {
        delete[] _resource;
        _resource = std::exchange(rhs._resource, nullptr);
    }
    return *this;
}

SourceMovable::~SourceMovable()
{
    delete[] _resource;
}

const char* SourceMovable::get()
{
    return _resource;
}
