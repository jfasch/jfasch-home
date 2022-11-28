#pragma once

#include <gtest/gtest.h>
#include <filesystem>
#include <string>
#include <stdlib.h>
#include <string.h>

struct filesystem_suite : public ::testing::Test
{
    filesystem_suite()
    {
        auto tmpdir = std::filesystem::temp_directory_path();
        std::string tmpdir_template = tmpdir / "filesystem_suite-XXXXXX";
        char* tmpdir_template_c = new char[tmpdir_template.size()+1];
        strcpy(tmpdir_template_c, tmpdir_template.c_str());

        char* retname = mkdtemp(tmpdir_template_c);
        if (retname == NULL)
            throw std::runtime_error(strerror(errno));

        dirname = retname;
    }

    ~filesystem_suite()
    {
        std::filesystem::remove_all(dirname);
    }

    std::filesystem::path dirname;
};
