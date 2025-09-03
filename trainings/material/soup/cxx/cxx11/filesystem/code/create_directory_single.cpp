#include "suite.h"

#include <gtest/gtest.h>

#include <filesystem>
#include <stdexcept>
#include <fstream>

TEST_F(filesystem_suite, create_directory_single)
{
    std::filesystem::create_directory(dirname / "parent");
    std::filesystem::create_directory(dirname / "parent/child");

    std::ofstream(dirname / "parent/child/file.txt");

    ASSERT_TRUE(std::filesystem::is_regular_file(dirname / "parent/child/file.txt"));
}
