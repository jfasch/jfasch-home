#include "suite.h"

TEST_F(filesystem_suite, cwd_chdir)
{
    std::filesystem::current_path(dirname);

    std::filesystem::path cwd = std::filesystem::current_path();
    ASSERT_EQ(cwd, dirname);
}
