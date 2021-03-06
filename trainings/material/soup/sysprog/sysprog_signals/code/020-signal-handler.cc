#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <assert.h>

using std::cout;
using std::endl;


static sig_atomic_t quit;
static void termination_handler(int signal)
{
    char buffer[64];
    sprintf(buffer, "handler called, signal=%d\n", signal);
    ssize_t nwritten = write(STDOUT_FILENO, buffer, strlen(buffer));
    assert(nwritten > 0);
    assert((size_t)nwritten == strlen(buffer));

    quit = true;
}

int main(void)
{
    cout << getpid() << endl;

    struct sigaction term_action;
    memset(&term_action, 0, sizeof(term_action));
    term_action.sa_handler = termination_handler;

    int error;
    error = sigaction(SIGTERM, &term_action, NULL);
    assert(!error);
    error = sigaction(SIGINT, &term_action, NULL);
    assert(!error);

    while (!quit) {
        int error = pause();
        if (error)
            cout << "pause: error; errno=" << errno << '(' << strerror(errno) << ')' << endl;
    }
    return 0;
}
