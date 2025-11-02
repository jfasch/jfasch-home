#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <print>

static void handler(int signal)
{
    static const char msg[] = "signal handler\n";
    write(STDOUT_FILENO, msg, sizeof(msg));
}

int main()
{
    /* timer creation */
    timer_t timer;                                     // <-- timer handle
    sigevent event = {0};
    event.sigev_notify = SIGEV_SIGNAL;                 // <-- expiry by signal ...
    event.sigev_signo = SIGRTMIN;                      // <-- ... namely SIGRTMIN

    int rv = timer_create(CLOCK_MONOTONIC, &event, &timer);
    if (rv == -1) {
        perror("timer_create");
        return 1;
    }

    /* timer signal handling */                        // <-- (nothing new)
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    /* timer activation */
    struct itimerspec sp = {
        {0,0},                                         // <-- one-shot (no interval)
        {3,0},                                         // <-- {sec,nsec}
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
