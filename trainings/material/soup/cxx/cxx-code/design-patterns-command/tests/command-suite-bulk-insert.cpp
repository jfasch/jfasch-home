#include <gtest/gtest.h>

#include <socialdb.h>
#include <social-db-commands.h>


TEST(command_suite, bulk_insert)
{
    SocialDB db;

    SocialDBBulkInsertCommand bic;
    bic.add(SocialDBInsertCommand("1037190666", "Joerg", "Faschingbauer"));
    bic.add(SocialDBInsertCommand("1234250497", "Caro", "Faschingbauer"));
    bic.add(SocialDBInsertCommand("2345110695", "Johanna", "Faschingbauer"));

    SocialDBCommand* c = &bic;          // <--- used as-a base
    c->execute(db);

    ASSERT_EQ(db.size(), 3);
}
