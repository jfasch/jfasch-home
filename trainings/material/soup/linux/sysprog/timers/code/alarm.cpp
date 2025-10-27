#include <unistd.h>
#include <print>

int main()
{
    unsigned int prev_remain = alarm(1);
    std::println("previous remaining: {}", prev_remain);
    pause();
    return 0;
}
