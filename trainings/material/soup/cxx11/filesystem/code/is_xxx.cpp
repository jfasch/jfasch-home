#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

TEST_F(filesystem_suite, is_xxx)
{
    std::filesystem::create_directory(dirname / "subdir");
    ASSERT_TRUE(std::filesystem::is_directory(dirname / "subdir"));

    std::ofstream(dirname / "file");
    ASSERT_TRUE(std::filesystem::is_regular_file(dirname / "file"));
}
