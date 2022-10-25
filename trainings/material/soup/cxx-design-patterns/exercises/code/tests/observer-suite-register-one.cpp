#include <gtest/gtest.h>

#include <social-db-observable.h>

namespace {

class MyObserver : public SocialDB_Observable::NewCitizenObserver
{
public:
    const std::string& new_citizen() const
    {
        return _new_citizen_svnr;
    }

    void new_citizen_added(const std::string& svnr) override
    {
        _new_citizen_svnr = svnr;
    }

private:
    std::string _new_citizen_svnr;
};

}

TEST(observer_suite, register_one)
{
    SocialDB_Observable db;

    MyObserver observer;
    db.register_new_citizen_notification(&observer);

    db.insert("1037190666", "Joerg", "Faschingbauer");

    ASSERT_EQ(observer.new_citizen(), "1037190666");
}
