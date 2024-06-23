#pragma once

#include "sink.h"

#include <sqlite3.h>


class SQLite3Error : public std::exception
{
public:
    SQLite3Error(int code, const std::string& prefix);
    virtual const char* what() const noexcept;
private:
    std::string _msg;
};

class SinkSQLite3 : public Sink
{
public:
    SinkSQLite3(const std::string& db);
    ~SinkSQLite3();

    void output(const Measurements& data) override;

    static inline const char* create_table_statement = "create table measurements (name text, value real);";

private:
    sqlite3* _db;
};
