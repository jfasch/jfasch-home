#include <unistd.h>
#include <print>

int main()
{
    std::println("PID={}", getpid());
    for(;;);
    return 0;
}
