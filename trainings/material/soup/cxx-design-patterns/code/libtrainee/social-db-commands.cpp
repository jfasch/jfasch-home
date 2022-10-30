#include "social-db-commands.h"


void SocialDBInsertCommand::execute(SocialDB& db)
{
    try {
        db.insert(_svnr, _firstname, _lastname);
    }
    catch (const SocialDB::NotInserted& e) {
        _error = e;
    }
}

void SocialDBInsertCommand::result() const
{
    if (_error)
        throw _error.value();
}

void SocialDBFindCommand::execute(SocialDB& db)
{
    try {
        _result = db.find(_svnr);
    }
    catch (const SocialDB::NotFound& e) {
        _result = e;
    }
}

SocialDB::Person SocialDBFindCommand::result() const
{
    if (const SocialDB::Person* p = std::get_if<SocialDB::Person>(&_result))
        return *p;
    else
        throw std::get<SocialDB::NotFound>(_result);
}

void SocialDBDropCommand::execute(SocialDB& db)
{
    db.drop();
}

SocialDBBulkInsertCommand::SocialDBBulkInsertCommand(
    std::initializer_list<std::tuple<std::string, std::string, std::string>> init)
{
    for (const auto& [svnr, firstname, lastname]: init)
        _commands.push_back(SocialDBInsertCommand(svnr, firstname, lastname));
}

void SocialDBBulkInsertCommand::add(const SocialDBInsertCommand& ic)
{
    _commands.push_back(ic);
}

void SocialDBBulkInsertCommand::execute(SocialDB& db)
{
    for (auto& c: _commands)
        c.execute(db);
}
