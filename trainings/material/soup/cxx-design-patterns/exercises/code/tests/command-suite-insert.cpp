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
