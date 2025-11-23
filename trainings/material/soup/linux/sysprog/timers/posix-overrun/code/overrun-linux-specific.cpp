#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(int signal, siginfo_t* info,       // <-- SA_SIGINFO handler
                    void* ctx)
{
    std::println("{} overruns", info->si_overrun);
}

int main()
{
    timer_t timer;

    sigevent event = {0};
    event.sigev_notify = SIGEV_SIGNAL;
    event.sigev_signo = SIGRTMIN;

    int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    struct sigaction sa = { 0 };
    sa.sa_sigaction = handler;                         // <-- SA_SIGINFO handler
    sa.sa_flags = SA_SIGINFO;                          // <-- 

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
