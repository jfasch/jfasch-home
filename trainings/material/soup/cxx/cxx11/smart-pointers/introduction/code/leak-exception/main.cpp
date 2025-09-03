#include "f.h"
#include <stdexcept>

int main()
{
    try {
        f();
    }
    catch (const std::runtime_error&) {}
    return 0;
}
