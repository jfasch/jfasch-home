#include <gtest/gtest.h>

#include <socialdb.h>
#include <social-db-commands.h>


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
