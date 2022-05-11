#include <thread>
#include <vector>
#include <iostream>
#include <string>

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

using std::thread;
using std::vector;
using std::cout;
using std::endl;
using std::string;


static void alarm_handler(int)
{
    char msg[] = "alarm\n";
    ssize_t nwritten = write(STDOUT_FILENO, msg, sizeof(msg));
    assert(nwritten>0);
    int error = alarm(3);
    if (error)
        perror("alarm");
}

static void consume_pipe(std::string name)
{
    while (true) {
        cout << "open pipe " << name << endl;
        int fd = open(name.c_str(), O_RDONLY);
        cout << "(done) open pipe " << name << endl;
        if (fd == -1) {
            perror("open");
            continue;
        }
        
        char buffer[64];
        ssize_t nread, nwritten;

        nread = read(fd, buffer, sizeof(buffer));
        if (nread == -1) {
            perror("read");
            goto out;
        }
        if (nread == 0) {
            cout << "not expecting eof because I read only once" << endl;
            goto out;
        }

        nwritten = write(STDOUT_FILENO, buffer, nread);
        if (nwritten == -1) {
            perror("write");
            goto out;
        }
        if (nwritten == 0) {
            assert(!"writing 0 bytes?");
            goto out;
        }
        assert(nwritten == nread);

    out:
        close(fd);
    }
}

int main(int argc, char** argv)
{
    cout << getpid() << endl;

    struct sigaction alarm_action;
    memset(&alarm_action, 0, sizeof(alarm_action));
    alarm_action.sa_handler = alarm_handler;

    int error = sigaction(SIGALRM, &alarm_action, NULL);
    assert(!error);

    alarm(3);

    std::vector<thread> threads;
    for (int i=1; i<argc; i++) {
        string pipename = argv[i];
        threads.push_back(thread([pipename](){consume_pipe(pipename);}));
    }

    for (auto& t: threads)
        t.join();

    return 0;
}
