#pragma once

#include "sink.h"


class SinkMovable : public Sink
{
public:
    SinkMovable(const char* resource);
    SinkMovable(SinkMovable&&);
    SinkMovable& operator=(SinkMovable&&);
    ~SinkMovable();

    const char* resource() const { return _resource; }
    void put(const std::string& s) override;

private:
    char* _resource;
};
