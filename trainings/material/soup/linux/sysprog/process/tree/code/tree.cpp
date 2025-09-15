#include <unistd.h>

#include <print>

int main(int argc, char** argv)
{
    std::println("PID: {}", getpid());                // <--- self's PID
    std::println("PPID: {}", getppid());              // <--- parent's PID

    return 0;
}
