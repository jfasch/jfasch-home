#include "sink-copyable.h"

#include <iostream>
#include <string>


SinkCopyable::SinkCopyable(const std::string& resource)
: _resource(resource) {}

void SinkCopyable::put(const std::string& s)
{
    std::cout << "SinkCopyable: " << s << " (resource: " << _resource << ')' << std::endl;
}
