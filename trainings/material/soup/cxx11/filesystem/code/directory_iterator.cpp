#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

TEST_F(filesystem_suite, directory_iterator)
{
    std::filesystem::create_directory(dirname / "subdir1");
    std::filesystem::create_directory(dirname / "subdir2");
    std::ofstream(dirname / "subdir1/file");
    std::ofstream(dirname / "subdir2/file");
    std::ofstream(dirname / "file1");
    std::ofstream(dirname / "file2");

    std::set<std::filesystem::path> entries;         // <--- iteration order is not (necessarily) creation order
    auto diriter = std::filesystem::directory_iterator(dirname);
    for (const auto& entry: diriter)
        entries.insert(entry);

    ASSERT_EQ(entries.size(), 4);                    // <--- not 6! (no recursion)

    ASSERT_TRUE(entries.contains(dirname / "subdir1"));
    ASSERT_TRUE(entries.contains(dirname / "subdir2"));
    ASSERT_TRUE(entries.contains(dirname / "file1"));
    ASSERT_TRUE(entries.contains(dirname / "file2"));
}
