#pragma once

#include "sink.h"

#include <vector>
#include <memory>


class SinkComposite : public Sink
{
public:
    void output(const Measurements& data) override;
    void add_sink(std::unique_ptr<Sink>&& sink);
private:
    std::vector<std::unique_ptr<Sink>> _sinks;
};
