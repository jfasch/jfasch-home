#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <print>

static void timer_expired(int sig)
{
    assert(sig == SIGALRM);
    const char msg[] = "expired\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
}


int main()
{
    struct sigaction sa = { 0 };
    sa.sa_handler = timer_expired;

    int rv = sigaction(SIGALRM, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    unsigned int prev_remain = alarm(1);
    std::println("previous remaining: {}", prev_remain);
    rv = pause();
    if (rv == -1) {
        if (errno == EINTR)
            std::println("pause() interrupted");
        else {
            perror("pause");
            return 1;
        }
    }
    return 0;
}
