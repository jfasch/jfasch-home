#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static timer_t timer;

static void handler(int signal)
{
    int overrun_count = timer_getoverrun(timer);
    if (overrun_count == -1) {
        perror("timer_getoverrun");
        exit(1);
    }
    else
        std::println("{} overruns", overrun_count);    // <-- undefined behavior: not async signal safe
}

int main()
{
    sigevent event = {0};
    event.sigev_notify = SIGEV_SIGNAL;
    event.sigev_signo = SIGRTMIN;

    int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    struct itimerspec sp = {
        {0,1},
        {1,0},
    };
    rv = timer_settime(timer, 0 /*relative*/,
                       &sp,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    while (true) {
        int rv = pause();
        if (rv == -1) {
            if (errno == EINTR)
                continue;
            else {
                perror("pause");
                return 1;
            }
        }
    }

    return 0;
}
