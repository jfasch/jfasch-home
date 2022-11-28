#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>
#include <fstream>

TEST_F(filesystem_suite, recursive_directory_iterator)
{
    std::filesystem::create_directory(dirname / "subdir1");
    std::filesystem::create_directory(dirname / "subdir2");
    std::ofstream(dirname / "subdir1/file");
    std::ofstream(dirname / "subdir2/file");
    std::ofstream(dirname / "file1");
    std::ofstream(dirname / "file2");

    auto diriter = std::filesystem::recursive_directory_iterator(dirname);
    std::set<std::filesystem::path> entries;
    for (const auto& entry: diriter)
        entries.insert(entry);

    ASSERT_EQ(entries.size(), 6);                  // <--- *recursive*: hitting entries in subdirs too

    ASSERT_TRUE(entries.contains(dirname / "subdir1"));
    ASSERT_TRUE(entries.contains(dirname / "subdir2"));
    ASSERT_TRUE(entries.contains(dirname / "subdir1/file"));
    ASSERT_TRUE(entries.contains(dirname / "subdir2/file"));
    ASSERT_TRUE(entries.contains(dirname / "file1"));
    ASSERT_TRUE(entries.contains(dirname / "file2"));
}
