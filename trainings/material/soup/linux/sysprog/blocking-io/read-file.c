#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    // rotate disk, or whatever is necessary to get a hand on
    // /etc/passwd --> FILE DESCRIPTOR
    int fd = open("/etc/passwd", O_RDONLY);

    // error handling (/etc/passwd might not exist, o rI might not
    // have permissions to read it)
    if (fd == -1) {
        perror("open()");
        exit(1);
    }

    // allocate buffer, and *read* in a loop until done
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
