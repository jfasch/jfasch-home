#include <unistd.h>
#include <print>

int main()
{
    std::println("PID={}", getpid());
    int* bad = nullptr;
    *bad = 666;
    return 0;
}
