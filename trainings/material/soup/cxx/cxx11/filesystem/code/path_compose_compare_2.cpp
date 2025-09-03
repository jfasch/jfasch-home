#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>

TEST_F(filesystem_suite, path_compose_compare_2)
{
    std::filesystem::path fn = "/etc";
    std::filesystem::path passwd = fn / "passwd";

    ASSERT_EQ(passwd, "/etc/passwd");
}
