#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>

TEST_F(filesystem_suite, path_abs_rel)
{
    std::filesystem::path abspath = "/etc/passwd";
    ASSERT_TRUE(abspath.is_absolute());
    ASSERT_FALSE(abspath.is_relative());

    std::filesystem::path relpath = "etc/passwd";
    ASSERT_FALSE(relpath.is_absolute());
    ASSERT_TRUE(relpath.is_relative());
}
