#include "loop.h"
#include "source-a.h"
#include "sink-1.h"

int main()
{
    SourceA source;
    Sink1 sink;
    Loop loop(source, sink);
    loop.doit(2);
    return 0;
}
