#include <stdlib.h>
#include <print>

int main(int argc, char** argv)
{
    const char* foo_value = getenv("FOO");
    if (foo_value != nullptr)
        std::println("FOO={}", foo_value);
    else
        std::println("FOO is not set");

    return 0;
}
