#pragma once

#include <socialdb.h>

#include <set>


class SocialDB_Observable : public SocialDB
{
public:
    class ObserverAlreadyRegistered : public std::exception 
    {
    public:
        virtual const char* what() const noexcept { return "Observer already registered"; }
    };
    class ObserverNotRegistered : public std::exception 
    {
    public:
        virtual const char* what() const noexcept { return "Observer not registered"; }
    };

public:
    class NewCitizenObserver
    {
    public:
        virtual ~NewCitizenObserver() {}
        virtual void new_citizen_added(const std::string& svnr) = 0;
    };

public:
    void insert(const std::string& svnr, const std::string& firstname, const std::string& lastname);

    void register_new_citizen_notification(NewCitizenObserver*);
    void unregister_new_citizen_notification(NewCitizenObserver*);

private:
    std::set<NewCitizenObserver*> _new_citizen_observers;
};
