#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>

TEST_F(filesystem_suite, create_directory_error)
{
    ASSERT_THROW(std::filesystem::create_directory(dirname / "parent/child"),
                 std::filesystem::filesystem_error);
}
