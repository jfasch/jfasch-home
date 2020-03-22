#include <thread>
#include <vector>
#include <iostream>
#include <string>

#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using std::thread;
using std::vector;
using std::cout;
using std::endl;
using std::string;


static void consume_pipe(std::string name)
{
    while (true) {
        int fd = open(name.c_str(), O_RDONLY);
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
    std::vector<thread> threads;
    for (int i=1; i<argc; i++) {
        string pipename = argv[i];
        threads.push_back(thread([pipename](){consume_pipe(pipename);}));
    }

    for (auto& t: threads)
        t.join();

    return 0;
}
