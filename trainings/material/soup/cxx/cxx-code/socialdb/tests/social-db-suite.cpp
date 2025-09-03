#include <gtest/gtest.h>

#include <socialdb.h>


TEST(socialdb_suite, insert)
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

TEST(socialdb_suite, duplicate)
{
    SocialDB db;
    db.insert("1037190666", "Joerg", "Faschingbauer");

    try {
        db.insert("1037190666", "Joerg", "Faschingbauer");
        ASSERT_FALSE(true);
    }
    catch (const SocialDB::NotInserted&) {}

    // -Werror=restrict
    // ASSERT_THROW(
    //     db.insert("1037190666", "Joerg", "Faschingbauer"),
    //     SocialDB::NotInserted);
}

TEST(socialdb_suite, init)
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

TEST(socialdb_suite, find)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    auto [firstname, lastname] = db.find("1037190666");
    ASSERT_EQ(firstname, "Joerg");
    ASSERT_EQ(lastname, "Faschingbauer");
}

TEST(socialdb_suite, notfound)
{
    SocialDB db;
    try {
        db.find("1037190666");
        ASSERT_FALSE(true);
    }
    catch (const SocialDB::NotFound&) {}

    // -Werror=restrict
    // ASSERT_THROW(
    //     db.find("1037190666"), 
    //     SocialDB::NotFound);
}

TEST(socialdb_suite, drop)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}}};
    ASSERT_EQ(db.size(), 1);

    db.drop();
    ASSERT_EQ(db.size(), 0);
}
