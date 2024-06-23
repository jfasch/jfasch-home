#include "sink-sqlite3.h"


SQLite3Error::SQLite3Error(int code, const std::string& prefix)
: _msg(prefix)
{
    _msg = prefix + sqlite3_errstr(code);
    _msg += " (";
    _msg += std::to_string(code);
    _msg += "\")";
}

const char* SQLite3Error::what() const noexcept
{
    return _msg.c_str();
}


static bool is_error(int code)
{
    return !(code == SQLITE_OK || code == SQLITE_ROW || code == SQLITE_DONE);
}

SinkSQLite3::SinkSQLite3(const std::string& db)
{
    int code = sqlite3_open(db.c_str(), &_db);
    if (is_error(code)) {
        _db = nullptr;
        throw SQLite3Error(code, "sqlite3_open");
    }
}

SinkSQLite3::~SinkSQLite3()
{
    if (_db != nullptr)
        sqlite3_close(_db);
}

void SinkSQLite3::output(const Measurements& data)
{
    for (auto [name, value] : data) {
        std::string stmt = "insert into measurements values ('" + name + "', " + std::to_string(value) + ");";
        int code = sqlite3_exec(_db, stmt.c_str(), nullptr, nullptr, nullptr);
        if (is_error(code))
            throw SQLite3Error(code, "sqlite3_exec");
    }
}
