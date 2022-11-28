#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <string>

TEST_F(filesystem_suite, path_iteration)
{
    std::filesystem::path path = "/etc/passwd";

    std::string components[3];

    size_t i = 0;
    for (const auto& component: path)
        components[i++] = component;

    ASSERT_EQ(components[0], "/");
    ASSERT_EQ(components[1], "etc");
    ASSERT_EQ(components[2], "passwd");
}
