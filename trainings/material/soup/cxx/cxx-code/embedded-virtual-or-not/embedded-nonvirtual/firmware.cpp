#include "loop.h"
#include "source-a.h"
#include "source-b.h"
#include "source.h"
#include "sink-1.h"
#include "sink-2.h"
#include "sink.h"


int main()
{
    SourceA source_a;
    Source<SourceA, SourceB> source(source_a);
    Sink1 sink_1;
    Sink<Sink1, Sink2> sink(sink_1);
    Loop loop(source, sink);
    loop.doit(2);
    return 0;
}
