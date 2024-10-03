#pragma once

#include "source.h"
#include "sink.h"

class Loop
{
public:
    Loop(Source& source, Sink& sink)
    : _source(source), _sink(sink) {}

    void doit(unsigned ntimes)
    {
        while (ntimes--) {
            std::string s = _source.get();             // <-- dynamic dispatch
            _sink.put(s);                              // <-- dynamic dispatch
        }
    }

private:
    Source& _source;                                   // <-- interface
    Sink& _sink;                                       // <-- interface
};
