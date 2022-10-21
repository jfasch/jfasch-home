#include <gtest/gtest.h>

#include <social-db.h>
#include <social-db-commands.h>


TEST(command_suite, insert)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    SocialDBInsertCommand ic("3456060486", "Philipp", "Lichtenberger");
    ic.execute(db);

    auto [firstname, lastname] = db.find("3456060486");
    ASSERT_EQ(firstname, "Philipp");
    ASSERT_EQ(lastname, "Lichtenberger");
}

// Commands are generally used by their interface. that is the plan.
TEST(command_suite, insert_by_base)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    SocialDBInsertCommand ic("3456060486", "Philipp", "Lichtenberger");
    SocialDBCommand* c = &ic;           // <--- Insert is-a Command
    c->execute(db);                     // <--- Insert used-as-a Command

    auto [firstname, lastname] = db.find("3456060486");
    ASSERT_EQ(firstname, "Philipp");
    ASSERT_EQ(lastname, "Lichtenberger");
}

TEST(command_suite, find)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    SocialDBFindCommand fc("1037190666");

    SocialDBCommand* c = &fc;           // <--- used as-a base
    c->execute(db);

    auto [firstname, lastname] = fc.result();
    ASSERT_EQ(firstname, "Joerg");
    ASSERT_EQ(lastname, "Faschingbauer");
}


// error cases: always cumbersome
// -------------------------------------------------------------------
TEST(command_suite, notfound)
{
    SocialDB db;

    SocialDBFindCommand fc("1037190666");

    SocialDBCommand* c = &fc;           // <--- used as-a base
    c->execute(db);

    ASSERT_THROW(fc.result(), SocialDB::NotFound);
}

TEST(command_suite, notinserted)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    SocialDBInsertCommand ic("1037190666", "Joerg", "Faschingbauer");

    SocialDBCommand *c = &ic;
    c->execute(db);

    ASSERT_THROW(ic.result(), SocialDB::NotInserted);
}

