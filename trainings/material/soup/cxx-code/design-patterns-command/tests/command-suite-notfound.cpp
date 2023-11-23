#include <gtest/gtest.h>

#include <socialdb.h>
#include <social-db-commands.h>


TEST(command_suite, notfound)
{
    SocialDB db;

    SocialDBFindCommand fc("1037190666");

    SocialDBCommand* c = &fc;           // <--- used as-a base
    c->execute(db);

    try {
        fc.result();
        FAIL();
    }
    catch (const SocialDB::NotFound&) {}

    // -Werror=restrict
    // ASSERT_THROW(fc.result(), SocialDB::NotFound);
}
