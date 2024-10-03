#pragma once

#include "source.h"
#include "sink.h"


template <class Source, class Sink>
class Loop
{
public:
    Loop(Source& source, Sink& sink)
    : _source(source), _sink(sink) {}

    void doit(unsigned ntimes)
    {
        while (ntimes--) {
            std::string s = _source.get();             // <-- visiting std::variant
            _sink.put(s);                              // <-- visiting std::variant
        }
    }

private:
    Source& _source;                                   // <-- std::variant
    Sink& _sink;                                       // <-- std::variant
};
