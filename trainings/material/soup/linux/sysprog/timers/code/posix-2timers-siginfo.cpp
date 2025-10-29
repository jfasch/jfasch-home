#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <print>
#include <iostream>

static timer_t timer1, timer2;

static void handler(int signal, siginfo_t* info, void* ctx)
{
    const timer_t* timer = (const timer_t*)info->si_value.sival_ptr;
    const char* msg;
    if (timer == &timer1)                              // <-- passed via event1 below
        msg = "timer1 expired\n";
    else if (timer == &timer2)                         // <-- passed via event2 below
        msg = "timer2 expired\n";
    else
        abort();

   write(STDOUT_FILENO, msg, strlen(msg));
}

int main()
{
    /* timer creation */                               // <-- create two timers
    sigevent event1 = {0};
    event1.sigev_notify = SIGEV_SIGNAL;
    event1.sigev_signo = SIGRTMIN;
    event1.sigev_value.sival_ptr = &timer1;            // <-- pass timer1 into handler

    int rv = timer_create(CLOCK_MONOTONIC, &event1, &timer1);
    if (rv == -1) {
        perror("timer_create (1)");
        return 1;
    }

    sigevent event2 = {0};
    event2.sigev_notify = SIGEV_SIGNAL;
    event2.sigev_signo = SIGRTMIN;
    event2.sigev_value.sival_ptr = &timer2;            // <-- pass timer2 into handler

    rv = timer_create(CLOCK_MONOTONIC, &event2, &timer2);
    if (rv == -1) {
        perror("timer_create (2)");
        return 1;
    }

    /* timer signal handling */ 
    struct sigaction sa = { 0 };
    sa.sa_flags = SA_SIGINFO;                          // <-- do the siginfo_t game altogether
    sa.sa_sigaction = handler;                         // <-- SA_SIGINFO handler

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
