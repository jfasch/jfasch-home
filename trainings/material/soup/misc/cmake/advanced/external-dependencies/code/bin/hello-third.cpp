#include "greeter-alias-db.h"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <DATABASE> <NAME>\n";
        return 1;
    }

    AliasDBGreeter(argv[2], argv[1]).sayhello();

    return 0;
}
