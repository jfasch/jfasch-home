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
    /* timer creation */                               // <-- create two timers
    timer_t timer1;
    sigevent event1 = {0};
    event1.sigev_notify = SIGEV_SIGNAL;
    event1.sigev_signo = SIGRTMIN;

    int rv = timer_create(CLOCK_MONOTONIC, &event1, &timer1);
    if (rv == -1) {
        perror("timer_create (1)");
        return 1;
    }

    timer_t timer2;
    sigevent event2 = {0};
    event2.sigev_notify = SIGEV_SIGNAL;
    event2.sigev_signo = SIGRTMIN;

    rv = timer_create(CLOCK_MONOTONIC, &event2, &timer2);
    if (rv == -1) {
        perror("timer_create (2)");
        return 1;
    }

    /* timer signal handling */ 
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    rv = sigaction(SIGRTMIN, &sa, nullptr);
    if (rv == -1) {
        perror("sigaction");
        return 1;
    }

    /* timer1 activation */
    struct itimerspec sp1 = {
        {1,0},                                         // <-- 1s period
        {3,0},                                         // <-- initial expiration in 3s
    };
    rv = timer_settime(timer1, 0 /*relative*/,
                       &sp1,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime (1)");
        return 1;
    }

    /* timer2 activation */
    struct itimerspec sp2 = {
        {1,500*1000*1000},                             // <-- 1.5s period
        {1,0},                                         // <-- initial expiration in 1s
    };
    rv = timer_settime(timer2, 0 /*relative*/,
                       &sp2,
                       nullptr);
    if (rv == -1) {
        perror("timer_settime (2)");
        return 1;
    }

    while (true) {
        rv = pause();
        if (rv == -1) { 
            if (errno != EINTR) {
                perror("pause");
                return 1;
            }
        }
    }

    return 0;
}
