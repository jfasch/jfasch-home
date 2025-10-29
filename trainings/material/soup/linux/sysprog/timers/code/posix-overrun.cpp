#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(int signal, siginfo_t* info , void* ctx)
{
    // static const char msg[] = "timer expired\n";
    // write(STDOUT_FILENO, msg, sizeof(msg));

    if (info->si_overrun > 0) {
        static const char msg[] = "overrun";
        write(STDOUT_FILENO, msg, sizeof(msg));
    }
}

int main()
{
    /* timer creation */
    timer_t timer;
    sigevent event = {0};
    event.sigev_notify = SIGEV_SIGNAL;
    event.sigev_signo = SIGRTMIN;

    int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    /* timer signal handling */ 
    struct sigaction sa = { 0 };
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    /* timer activation */
    struct itimerspec sp = {
        {0,1},                                      // <-- 1 us periodic
        {1,0},                                         // <-- start immediately
    };
    rv = timer_settime(timer, 0 /*relative*/,
                       &sp,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    // sigset_t blocked;
    // sigemptyset(&blocked);
    // sigaddset(&blocked, SIGRTMIN);
    // rv = sigprocmask(SIG_BLOCK, &blocked, nullptr);
    // if (rv == -1) {
    //     perror("sigprocmask");
    //     return 1;
    // }

    while (true) {
        rv = pause();
        if (rv == -1) {
            if (errno == EINTR) {
                int overrun_count = timer_getoverrun(timer);
                if (overrun_count == -1) {
                    perror("timer_getoverrun");
                    return 1;
                }
                else
                    std::println("{} overruns", overrun_count);
            }
            else {
                perror("pause");
                return 1;
            }
        }
    }

    return 0;
}
