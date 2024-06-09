#ifndef GREETER_ALIAS_DB_H
#define GREETER_ALIAS_DB_H

#include "greeter.h"
#include <sqlite3.h>
#include <string>

class AliasDBGreeter : public Greeter
{
public:    
    AliasDBGreeter(const std::string& name, const std::string& db);
    void sayhello() override;

private:
    const std::string _name;
    sqlite3* _db;

public:
    size_t sql_nfound;
    std::string sql_found;
};

#endif
