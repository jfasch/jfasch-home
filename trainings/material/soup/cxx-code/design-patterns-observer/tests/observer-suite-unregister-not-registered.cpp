#include <gtest/gtest.h>

#include <social-db-observable.h>

namespace {

class MyObserver : public SocialDB_Observable::NewCitizenObserver
{
public:
    void new_citizen_added(const std::string& svnr) override {}
};

}

TEST(observer_suite, unregister_not_registered)
{
    SocialDB_Observable db;
    MyObserver observer;
    ASSERT_THROW(db.unregister_new_citizen_notification(&observer), SocialDB_Observable::ObserverNotRegistered);
}
