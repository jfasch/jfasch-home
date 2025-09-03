#include "social-db-observable.h"


void SocialDB_Observable::insert(
    const std::string& svnr, 
    const std::string& firstname, 
    const std::string& lastname)
{
    SocialDB::insert(svnr, firstname, lastname);
    for (auto observer: _new_citizen_observers)
        observer->new_citizen_added(svnr);
}

void SocialDB_Observable::register_new_citizen_notification(
    NewCitizenObserver* o)
{
    if (_new_citizen_observers.find(o) != _new_citizen_observers.end())
        throw ObserverAlreadyRegistered();

    _new_citizen_observers.insert(o);
}

void SocialDB_Observable::unregister_new_citizen_notification(
    NewCitizenObserver* o)
{
    auto num_erased = _new_citizen_observers.erase(o);
    if (num_erased == 0)
        throw ObserverNotRegistered();
}
