#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    // allocate space (in kernel) for a TCP connection. the handle to
    // it is a FILE DESCRIPTOR, again.
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // error handling
    if (fd == -1) {
        perror("socket()");
        exit(1);
    }

    // connect to peer/server. fill in address structure first.
    {
        int error;

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(1234);
        inet_aton("127.0.0.1", &addr.sin_addr);

        // this send out packets via network hardware, does all the
        // tedious timeout handling, DMA, and whatnot.
        error = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
        // error handling
        if (error == -1) {
            perror("connect()");
            exit(1);
        }
    }

    // allocate buffer, and *read* in a loop until done. NOTE THIS IS
    // THE SAME AS WITH FILES: "Everything is a file!".
    char buffer[16];
    while (1) {
        ssize_t nbytes_read = read(fd, buffer, sizeof(buffer));
        if (nbytes_read == 0) // end-of-file (EOF) -> done
            break;
        write(STDOUT_FILENO, buffer, nbytes_read);
    }

    // free resources
    close(fd);
    return 0;
}
