#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


int main(void)
{
    int error;

    // setup set of signals that are meant to terminate us
    sigset_t termination_signals;
    sigemptyset(&termination_signals);
    sigaddset(&termination_signals, SIGTERM);
    sigaddset(&termination_signals, SIGINT);
    sigaddset(&termination_signals, SIGQUIT);

    // block asynchronous delivery for those
    error = sigprocmask(SIG_BLOCK, &termination_signals, NULL);
    if (error) {
        perror("sigprocmask(SIGTERM|SIGINT|SIGQUIT)");
        exit(1);
    }

    // wait for one of these signals to arrive. EINTR handling is
    // always good to have in larger programs. for example, libraries
    // might make use of signals in their own weird way - thereby
    // disturbing their users most impolitely by interrupting every
    // operation they synchronously wait for.
    while (1) {
        int sig;
        error = sigwait(&termination_signals, &sig);
        if (error && errno == EINTR) {
            perror("sigwait");
            continue;
        }
        
        printf("received termination signal %d\n", sig);
        break;
    }

    return 0;
}
