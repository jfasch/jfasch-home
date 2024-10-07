#include <loop.h>
#include <source-copyable.h>
#include <source-movable.h>
#include <sink-copyable.h>
#include <sink-movable.h>

#include <iostream>


static void usage(const char* progname)
{
    std::cerr << progname << " {copy|move}" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    std::string what = argv[1];

    SourceCopyable source_copyable("copyable");
    SourceMovable source_movable("movable");
    SinkCopyable sink_copyable("copyable");
    SinkMovable sink_movable("movable");

    Source* source;
    Sink* sink;

    if (what == "copy") {
        source = &source_copyable;
        sink = &sink_copyable;
    }
    else if (what == "move") {
        source = &source_movable;
        sink = &sink_movable;
    }
    else {
        usage(argv[0]);
        return 1;
    }

    Loop loop(source, sink);
    loop.doit(2);
    return 0;
}
