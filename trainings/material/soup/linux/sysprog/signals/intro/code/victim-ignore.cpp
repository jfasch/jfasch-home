#include <unistd.h>
#include <signal.h>
#include <print>


int main()
{
    std::println("PID={}", getpid());

    struct sigaction sa = { 0 };
    sa.sa_handler = SIG_IGN;

    int rv = sigaction(SIGTERM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    for(;;);
    return 0;
}
