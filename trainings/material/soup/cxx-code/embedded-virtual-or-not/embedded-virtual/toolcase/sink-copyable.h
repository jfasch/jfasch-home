#pragma once

#include "sink.h"


class SinkCopyable : public Sink
{
public:
    SinkCopyable(const std::string& resource);

    const std::string& resource() const { return _resource; }
    void put(const std::string& s) override;

private:
    std::string _resource;
};
