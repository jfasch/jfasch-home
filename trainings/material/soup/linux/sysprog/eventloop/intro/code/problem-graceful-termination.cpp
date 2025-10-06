#include <unistd.h>
#include <signal.h>
#include <string>
#include <regex>
#include <print>

static volatile sig_atomic_t quit = false;

static void handler(int signal)
{
    if (signal == SIGTERM || signal == SIGINT)
        quit = 1;
}

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
    struct sigaction sa = { 0 };
    sa.sa_handler = handler;

    int rv = sigaction(SIGTERM, &sa, nullptr);         // <-- install async handler
    if (rv == -1) {
        perror("sigaction(SIGTERM)");
        return 1;
    }
    rv = sigaction(SIGINT, &sa, nullptr);              // <-- install async handler
    if (rv == -1) {
        perror("sigaction(SIGINT)");
        return 1;
    }
    
    static const std::regex re_line("^(\\d+)\\s+(\\w+)\\s+(\\w+)\\s*$");
    Database db;

    while (!quit) {
        char line[64];
        ssize_t nread = read(STDIN_FILENO,             // <-- blocking read from fd 0
                             line, sizeof(line)-1);
        if (nread == -1) {
            if (errno == EINTR)
                continue;
            perror("read");
            return 1;
        }
        if (nread == 0)
            break;

        std::string sline(line, nread);
        std::smatch match;
        if (std::regex_search(sline, match, re_line))
            db.insert(std::stoi(match[1].str()), match[2].str(), match[3].str());
    }

    db.commit();                                       // <-- commit on the way out
                                                       //     (-> "graceful shutdown")
    return 0;
};
