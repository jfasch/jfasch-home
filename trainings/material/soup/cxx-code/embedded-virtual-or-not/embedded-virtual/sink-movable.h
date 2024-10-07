#pragma once

#include "sink.h"
#include <iostream>

class SinkMovable : public Sink
{
public:
    SinkMovable(size_t resource_size)
    : _resource(new char[resource_size]) {}

    SinkMovable(SinkMovable&& rhs)
    : _resource(std::exchange(rhs._resource, 0)) {}

    SinkMovable&& operator=(SinkMovable&& rhs)
    {
        if (this != &rhs)
            _resource = std::exchange(rhs._resource, 0);
        return *this;
    }

    ~SinkMovable()
    {
        delete[] _resource;
    }

    void put(const std::string& s) override
    {
        std::cout << "Sink2: " << s << std::endl;
    }

private:
    char* _resource;
};
