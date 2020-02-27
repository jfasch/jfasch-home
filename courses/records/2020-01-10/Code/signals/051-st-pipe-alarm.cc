#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <assert.h>
#include <string.h>

using std::cout;
using std::endl;

static void alarm_handler(int)
{
    char msg[] = "alarm\n";
    ssize_t nwritten = write(STDOUT_FILENO, msg, sizeof(msg));
    assert(nwritten>0);
    int error = alarm(3);
    if (error)
        perror("alarm");
}

int main(int, char** argv)
{
    cout << getpid() << endl;

    struct sigaction alarm_action;
    memset(&alarm_action, 0, sizeof(alarm_action));
    alarm_action.sa_handler = alarm_handler;

    int error = sigaction(SIGALRM, &alarm_action, NULL);
    assert(!error);

    alarm(3);

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    return 0;
}
