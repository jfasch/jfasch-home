#include <gtest/gtest.h>

#include <social-db.h>
#include <social-db-commands.h>


TEST(command_suite, drop)
{
    SocialDB db{{"1037190666", {"Joerg", "Faschingbauer"}},
                {"1234250497", {"Caro", "Faschingbauer"}},
                {"2345110695", {"Johanna", "Faschingbauer"}},
    };

    SocialDBDropCommand dc;

    SocialDBCommand* c = &dc;           // <--- used as-a base
    c->execute(db);

    dc.result();                        // <--- no error expected

    ASSERT_EQ(db.size(), 0);
}
