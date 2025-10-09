#pragma once

#include <string>
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
