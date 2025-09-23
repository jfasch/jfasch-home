#include <unistd.h>
#include <print>

int main()
{
    int bad = 1/0;
    std::println("{}", bad);
    return 0;
}
