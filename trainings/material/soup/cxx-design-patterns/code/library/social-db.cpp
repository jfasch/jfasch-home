#include "social-db.h"

#include <stdexcept>


SocialDB::SocialDB(std::initializer_list<std::pair<const std::string, Person>> init)
: _db(init) {}

void SocialDB::insert(
    const std::string& svnr, 
    const std::string& firstname, 
    const std::string& lastname)
{
    auto [_, inserted] = _db.insert(std::make_pair(svnr, Person(firstname, lastname)));
    if (! inserted)
        throw NotInserted(svnr + " not inserted");
}

const SocialDB::Person& SocialDB::find(const std::string& svnr) const
{
    auto found = _db.find(svnr);
    if (found != _db.end())
        return found->second;
    throw NotFound(svnr + " not found");
}
