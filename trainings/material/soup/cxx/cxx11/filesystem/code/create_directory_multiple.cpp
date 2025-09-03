#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

TEST_F(filesystem_suite, create_directory_multiple)
{
    std::filesystem::create_directories(dirname / "parent/child");
    std::ofstream(dirname / "parent/child/file.txt");

    ASSERT_TRUE(std::filesystem::is_regular_file(dirname / "parent/child/file.txt"));
}
