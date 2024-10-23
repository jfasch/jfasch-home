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
    int fd = open(filename, O_RDONLY);                 // <-- O_RDONLY
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat stat;
    int error = fstat(fd, &stat);                      // <-- determine file size (stat.st_size)
    if (error) {
        perror("fstat");
        return 1;
    }

    void* content = mmap(
        NULL,                                          // <-- (addr) let kernel choose address
        stat.st_size,                                  // <-- (length) extending from offset (0)
        PROT_READ,                                     // <-- (prot) memory access protection
        MAP_PRIVATE,                                   // <-- (flags) copy-on-write (read-only anyway)
        fd,                                            // <-- (fd) file mapping (as opposed to "anonymous")
        0                                              // <-- (offset) offset; map from beginning of file
    );
    if (content == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    close(fd);                                         // <-- abandon; mapping keeps a reference

    write(STDOUT_FILENO, content, stat.st_size);

    munmap(content, stat.st_size);                     // <-- (done anyway at exit)

    return 0;
}
