#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <string>

TEST_F(filesystem_suite, path_component_access)
{
    std::filesystem::path path = "/a/b/c/blah.txt";
    std::string filename_part = path.filename();

    ASSERT_EQ(filename_part, "blah.txt");

    std::string dir_part = path.parent_path();
    ASSERT_EQ(dir_part, "/a/b/c");

    path.replace_extension("TXT");
    ASSERT_EQ(path, "/a/b/c/blah.TXT");
}
