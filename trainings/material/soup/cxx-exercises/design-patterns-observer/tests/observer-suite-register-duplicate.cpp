#include <gtest/gtest.h>

#include <social-db-observable.h>

namespace {

class MyObserver : public SocialDB_Observable::NewCitizenObserver
{
public:
    void new_citizen_added(const std::string&) override {}
};

}

TEST(observer_suite, register_duplicate)
{
    SocialDB_Observable db;

    MyObserver observer;
    db.register_new_citizen_notification(&observer);

    ASSERT_THROW(db.register_new_citizen_notification(&observer), SocialDB_Observable::ObserverAlreadyRegistered);
}
