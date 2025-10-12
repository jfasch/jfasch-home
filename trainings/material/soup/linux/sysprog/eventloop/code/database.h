#pragma once

#include <string>
#include <regex>
#include <print>

struct Record
{
public:
    Record() = default;
    Record(int id, const std::string& firstname, const std::string& lastname)
    : id(id), firstname(firstname), lastname(lastname) {}

    operator bool() const { return id != -1; }

    const int id = -1;
    const std::string firstname; 
    const std::string lastname;
};

class Database
{
public:
    void insert(const Record& r) {
        std::println("insert id={}, firstname={}, lastname={}", r.id, r.firstname, r.lastname);
    }
    void commit() {
        std::println("commit");
    }
    void rollback() {
        std::println("rollback");
    }
};

Record split_line(const std::string& line)
{
    static const std::regex re_line("^(\\d+)\\s+(\\w+)\\s+(\\w+)\\s*$");

    std::smatch match;
    if (std::regex_search(line, match, re_line)) {
        return Record(std::stoi(match[1].str()), match[2].str(), match[3].str());
    }
    else
        return Record();
}
