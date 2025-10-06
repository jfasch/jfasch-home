#include <unistd.h>
#include <string>
#include <regex>
#include <print>

struct Database
{
    void insert(unsigned id, const std::string& firstname, const std::string& lastname) {
        std::println("insert id={}, firstname={}, lastname={}", id, firstname, lastname);
    }
    void commit() {
        std::println("commit");
    }
    void rollback() {
        std::println("rollback");
    }
};

int main()
{
    static const std::regex re_line("^(\\d+)\\s+(\\w+)\\s+(\\w+)\\s*$");
    Database db;

    while (true) {
        char line[64];
        ssize_t nread = read(STDIN_FILENO,             // <-- blocking read from fd 0
                             line, sizeof(line)-1);
        if (nread == -1) {
            perror("read");
            return 1;
        }
        if (nread == 0) {                              // <-- graceful shutdown on eof
            db.commit();
            return 0;
        }

        std::string sline(line, nread);
        std::smatch match;
        if (std::regex_search(sline, match, re_line))
            db.insert(std::stoi(match[1].str()), match[2].str(), match[3].str());
    }
    
    return 0;
};
