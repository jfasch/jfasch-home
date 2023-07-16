#include "greeter-alias-db.h"
#include <stdexcept>
#include <string>
#include <iostream>

AliasDBGreeter::AliasDBGreeter(const std::string& name, const std::string& db)
: _name(name)
{
    int error = sqlite3_open(db.c_str(), &_db);
    if (error) {
        std::string msg = "Nix open DB (";
        msg += sqlite3_errmsg(_db);
        msg += ')';
        sqlite3_close(_db);
        throw std::runtime_error(msg);
    }    
}

static int callback(void* vself, int argc, char** argv, char** colname)
{
    AliasDBGreeter* self = (AliasDBGreeter*)vself;
    std::cout << "argc: " << argc << '\n';
    if (argc == 0)
        throw std::runtime_error("nix found");
    self->sql_nfound++;
    self->sql_found = argv[0];
    return 0;
}

void AliasDBGreeter::sayhello()
{
    std::string stmt = "select name from aliases where alias = '";
    stmt += _name;
    stmt += "';";

    char* errmsg = nullptr;
    sql_nfound = 0;
    int error = sqlite3_exec(_db, stmt.c_str(), callback, this, &errmsg);
    if (error) {
        std::string msg = "Nix query DB (";
        msg += errmsg;
        msg += ')';
        sqlite3_free(errmsg);
        throw std::runtime_error(msg);
    }
    if (sql_nfound == 0)
        throw std::runtime_error(std::string("not found: ") + _name);
    if (sql_nfound > 1)
        throw std::runtime_error(std::string("duplicate: ") + _name);
    
    std::cout << "Hello " << sql_found << '\n';
}
