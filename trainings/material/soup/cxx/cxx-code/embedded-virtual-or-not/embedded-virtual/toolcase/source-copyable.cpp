#include "source-copyable.h"

#include <iostream>


SourceCopyable::SourceCopyable(const std::string& resource)
: _resource(resource) {}

const char* SourceCopyable::get()
{
    return _resource.c_str();
}
