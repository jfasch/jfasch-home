#include "sink-composite.h"


void SinkComposite::output(const Measurements& data)
{
    for (auto& sink: _sinks)
        sink->output(data);
}

void SinkComposite::add_sink(std::unique_ptr<Sink>&& sink)
{
    _sinks.push_back(std::move(sink));
}
