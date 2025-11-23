#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(int signal)
{
    static const char msg[] = "timer expired\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
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
    sa.sa_handler = handler;

    rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    struct itimerspec sp = {
        {0,1},                                         // <-- 1 nanosecond periodic
        {1,0},                                         // <-- start in one second
    };
    rv = timer_settime(timer, 0 /*relative*/,
                       &sp,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    sigset_t blocked;
    sigemptyset(&blocked);
    sigaddset(&blocked, SIGRTMIN);
    rv = sigprocmask(SIG_BLOCK, &blocked, nullptr);    // <-- block SIGRTMIN
    if (rv == -1) {
        perror("sigprocmask");
        return 1;
    }

    sleep(3);                                          // <-- give timer a chance to overrun

    int overrun_count = timer_getoverrun(timer);
    if (overrun_count == -1) {
        perror("timer_getoverrun");
        return 1;
    }
    else
        std::println("{} overruns", overrun_count);

    return 0;
}
