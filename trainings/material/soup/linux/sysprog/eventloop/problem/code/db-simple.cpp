#include "database.h"
#include <unistd.h>

int main()
{
    Database db;

    bool quit = false;
    while (!quit) {
        char line[64];
        ssize_t nread = read(STDIN_FILENO,             // <-- blocking read from fd 0
                             line, sizeof(line)-1);
        if (nread == -1) {
            perror("read");
            return 1;
        }
        if (nread == 0) {                              // <-- graceful shutdown on eof
            quit = true;
            continue;
        }

        std::string sline(line, nread);                // <-- (zero-termination!)
        if (Record r = split_line(sline))
            db.insert(r);
        else
            std::println(stderr, "invalid line: \"{}\"", sline);
    }

    db.commit();
    return 0;
};
