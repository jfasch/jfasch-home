#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    const char* srcfile;
    const char* dstfile;
    int srcfd;
    int dstfd;
    char buffer[1024];

    if (argc != 3) {
        fprintf(stderr, "%s: SRCFILE DSTFILE\n", argv[0]);
        return 1;
    }

    srcfile = argv[1];
    dstfile = argv[2];

    srcfd = open(srcfile, O_RDONLY);
    if (srcfd == -1) {
        const char* errstr = strerror(errno);
        fprintf(stderr, "%s: %s\n", srcfile, errstr);
        return 2;
    }

    dstfd = open(dstfile, O_WRONLY|O_CREAT|O_EXCL, 0666);
    if (dstfd == -1) {
        const char* errstr = strerror(errno);
        fprintf(stderr, "%s: %s\n", dstfile, errstr);
        return 3;
    }

    while (1) {
        ssize_t nread;
        ssize_t nwritten;

        nread = read(srcfd, buffer, sizeof(buffer));
        if (nread == -1) {
            const char* errstr = strerror(errno);
            fprintf(stderr, "read %s: %s\n", srcfile, errstr);
            return 4;
        }

        if (nread == 0) // end of file (EOF)
            break;

        nwritten = write(dstfd, buffer, nread);
        if (nwritten == -1) {
            const char* errstr = strerror(errno);
            fprintf(stderr, "write %s: %s\n", srcfile, errstr);
            return 5;
        }
    }

    return 0;
}
