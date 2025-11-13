#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <print>

static void handler(int signal, 
                    siginfo_t *info,                   // <-- signal *parameter*
                    void *ucontext)                    // <-- unused
{
    char msg[64] = {0};
    sprintf(msg, "signal handler: %d\n", info->si_value.sival_int);
    write(STDOUT_FILENO, msg, strlen(msg));
}

int main()
{
    timer_t timer;
    sigevent event = {0};
    event.sigev_notify = SIGEV_SIGNAL;
    event.sigev_signo = SIGRTMIN;
    event.sigev_value.sival_int = 42;                  // <-- additional info to be echoed back at expiration

    int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    struct sigaction sa = { 0 };
    sa.sa_flags = SA_SIGINFO;                          // <-- request additional info with signal
    sa.sa_sigaction = handler;                         // <-- different handler!

    rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    struct itimerspec sp = {
        .it_interval = {.tv_sec=0, .tv_nsec=0},
        .it_value    = {.tv_sec=3, .tv_nsec=0},
    };
    rv = timer_settime(timer, 0 /*relative*/,
                       &sp,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime");
        return 1;
    }

    rv = pause();
    if (rv == -1) {
        if (errno == EINTR)
            std::println("interrupted");
        else {
            perror("pause");
            return 1;
        }
    }

    return 0;
}
