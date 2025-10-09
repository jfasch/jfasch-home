#include "database.h"

#include <unistd.h>
#include <regex>

int main()
{
    static const std::regex re_line("^(\\d+)\\s+(\\w+)\\s+(\\w+)\\s*$");
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

        std::string sline(line, nread);
        std::smatch match;
        if (std::regex_search(sline, match, re_line))
            db.insert(std::stoi(match[1].str()), match[2].str(), match[3].str());
        else
            std::println(stderr, "invalid line: \"{}\"", sline);
    }

    db.commit();
    return 0;
};
