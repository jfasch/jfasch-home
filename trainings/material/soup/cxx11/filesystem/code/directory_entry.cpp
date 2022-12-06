#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

TEST_F(filesystem_suite, directory_entry)
{
    std::filesystem::create_directory(dirname / "subdir");
    std::ofstream(dirname / "file").write("Hallo", 5);

    std::filesystem::directory_entry subdir(dirname / "subdir");
    ASSERT_TRUE(subdir.is_directory());
    ASSERT_EQ(subdir.path(), dirname / "subdir");

    std::filesystem::directory_entry file(dirname / "file");
    ASSERT_TRUE(file.is_regular_file());
    ASSERT_EQ(file.path(), dirname / "file");
    ASSERT_EQ(file.file_size(), 5);
}
