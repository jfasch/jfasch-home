#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <string>

TEST_F(filesystem_suite, path_component_access)
{
    std::filesystem::path path = "/a/b/c/blah";
    std::string filename_part = path.filename();

    ASSERT_EQ(filename_part, "blah");

    std::string dir_part = path.parent_path();
    ASSERT_EQ(dir_part, "/a/b/c");
}
