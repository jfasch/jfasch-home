#include "blacklist.h"

Blacklist::Blacklist()
: _forbidden_names{"Joerg", "Caro", "Johanna", "Evi"} {}

bool Blacklist::is_forbidden(const std::string& name) const
{
    return _forbidden_names.contains(name);
}
