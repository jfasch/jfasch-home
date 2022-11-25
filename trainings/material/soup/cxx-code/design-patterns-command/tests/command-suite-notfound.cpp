#include <gtest/gtest.h>

#include <socialdb.h>
#include <social-db-commands.h>


TEST(command_suite, notfound)
{
    SocialDB db;

    SocialDBFindCommand fc("1037190666");

    SocialDBCommand* c = &fc;           // <--- used as-a base
    c->execute(db);

    ASSERT_THROW(fc.result(), SocialDB::NotFound);
}
