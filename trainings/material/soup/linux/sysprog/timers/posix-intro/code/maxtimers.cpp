#include <signal.h>
#include <time.h>
#include <print>

int main()
{
    int ntimers = 0;
    while (true) {
        timer_t timer;
        sigevent event = {0};
        event.sigev_notify = SIGEV_SIGNAL;
        event.sigev_signo = SIGRTMIN;

        int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
        if (rv == -1) {
            perror("timer_create");
            break;
        }
        ntimers++;
    }
    std::println("{} timers created", ntimers);
    return 0;
}
