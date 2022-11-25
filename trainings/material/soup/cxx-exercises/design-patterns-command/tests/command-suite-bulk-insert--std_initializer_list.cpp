#include <gtest/gtest.h>

#include <socialdb.h>
#include <social-db-commands.h>


TEST(command_suite, bulk_insert__std_initializer_list)
{
    SocialDB db;

    SocialDBBulkInsertCommand bic{
        { "1037190666", "Joerg", "Faschingbauer" },
        { "1234250497", "Caro", "Faschingbauer" },
        { "2345110695", "Johanna", "Faschingbauer" },
    };
    
    SocialDBCommand* c = &bic;          // <--- used as-a base
    c->execute(db);

    ASSERT_EQ(db.size(), 3);
}
