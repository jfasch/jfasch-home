#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>

TEST_F(filesystem_suite, path_compose_compare)
{
    std::filesystem::path fn = "/";
    fn /= "etc";
    fn /= "passwd";

    ASSERT_EQ(fn, "/etc/passwd");
}
