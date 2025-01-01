#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " FILENAME\n";
        return 1;
    }

    const char* filename = argv[1];
    int fd = open(filename, O_RDONLY);                 // <-- read-only!
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat stat;
    int error = fstat(fd, &stat);
    if (error) {
        perror("fstat");
        return 1;
    }

    void* content = mmap(
        NULL,
        stat.st_size,
        PROT_WRITE,                                    // <-- content is writeable
        MAP_PRIVATE,                                   // <-- and *private* -> COW
        fd,
        0
    );
    if (content == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    close(fd);

    ((char*)content)[0] = 'a';                         // <-- touch first couple bytes
    ((char*)content)[1] = 'b';
    ((char*)content)[2] = 'c';
    ((char*)content)[3] = 'd';

    munmap(content, stat.st_size);

    return 0;
}
