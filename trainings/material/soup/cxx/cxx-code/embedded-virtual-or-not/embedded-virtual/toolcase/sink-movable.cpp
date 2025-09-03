#include "sink-movable.h"

#include <iostream>
#include <utility>
#include <cstring>


SinkMovable::SinkMovable(const char* resource)
: _resource(new char[strlen(resource)+1])
{
    strcpy(_resource, resource);
}

SinkMovable::SinkMovable(SinkMovable&& rhs)
: _resource(std::exchange(rhs._resource, nullptr)) {}

SinkMovable& SinkMovable::operator=(SinkMovable&& rhs)
{
    if (this != &rhs) {
        delete[] _resource;
        _resource = std::exchange(rhs._resource, nullptr);
    }
    return *this;
}

SinkMovable::~SinkMovable()
{
    delete[] _resource;
}

void SinkMovable::put(const std::string& s)
{
    std::cout << "SinkMovable: " << s << " (resource: " << _resource << ')' << std::endl;
}
