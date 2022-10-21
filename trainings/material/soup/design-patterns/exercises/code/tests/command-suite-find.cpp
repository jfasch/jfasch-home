#include <gtest/gtest.h>

#include <social-db.h>
#include <social-db-commands.h>


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
