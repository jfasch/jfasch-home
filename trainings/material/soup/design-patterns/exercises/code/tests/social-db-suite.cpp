#include <gtest/gtest.h>

#include <social-db.h>


TEST(social_db_suite, insert)
{
    SocialDB db;
    db.insert("1037190666", "Joerg", "Faschingbauer");
    db.insert("1234250497", "Caro", "Faschingbauer");
    db.insert("2345110695", "Johanna", "Faschingbauer");

    ASSERT_EQ(db.size(), 3);

    auto jfasch = db.database().find("1037190666");
    ASSERT_EQ(jfasch->second.first, "Joerg");
    ASSERT_EQ(jfasch->second.second, "Faschingbauer");
}

TEST(social_db_suite, duplicate)
{
    SocialDB db;
    db.insert("1037190666", "Joerg", "Faschingbauer");
    ASSERT_THROW(
        db.insert("1037190666", "Joerg", "Faschingbauer"),
        SocialDB::NotInserted);
}

TEST(social_db_suite, init)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    ASSERT_EQ(db.size(), 3);

    auto jfasch = db.database().find("1037190666");
    ASSERT_EQ(jfasch->second.first, "Joerg");
    ASSERT_EQ(jfasch->second.second, "Faschingbauer");
}

TEST(social_db_suite, find)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    auto [firstname, lastname] = db.find("1037190666");
    ASSERT_EQ(firstname, "Joerg");
    ASSERT_EQ(lastname, "Faschingbauer");
}

TEST(social_db_suite, notfound)
{
    SocialDB db;
    ASSERT_THROW(
        db.find("1037190666"), 
        SocialDB::NotFound);
}

TEST(social_db_suite, drop)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}}};
    ASSERT_EQ(db.size(), 1);

    db.drop();
    ASSERT_EQ(db.size(), 0);
}
