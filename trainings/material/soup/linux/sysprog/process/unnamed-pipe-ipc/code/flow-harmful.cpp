#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <print>

struct data
{
    int sequence_number;
};

int main()
{
    int pipe_ends[2];
    if (pipe(pipe_ends) == -1) {
        perror("pipe");
        return 1;
    }

    int read_end = pipe_ends[0];
    int write_end = pipe_ends[1];

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        close(read_end);

        int cur_seq = 0;
        for (int i=0; i<5; i++) {
            data data = { cur_seq++ };
            ssize_t nwritten = write(write_end, &data, sizeof(data));
            if (nwritten == -1) {
                perror("write");
                exit(1);
            }
            sleep(1);
        }
        
        close(write_end);
        exit(0);
    }
    else {
        // close(write_end);                           // <-- NOT closing -> pinned

        while (true) {
            data data;
            ssize_t nread = read(read_end, &data, sizeof(data));
            if (nread == -1) {
                perror("read");
                exit(1);
            }
            if (nread == 0)  {
                std::println("seen EOF");
                break;
            }
            std::println("parent received: {}", data.sequence_number);
        }

        close(read_end);
        exit(0);
    }

    return 0;
}

