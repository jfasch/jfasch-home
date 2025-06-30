#include <gtest/gtest.h>
#include <array>

TEST(array_suite, structured_binding)
{
    std::array<int, 3> a = {200, 204, 203};
    auto [x,y,z] = a;
    ASSERT_EQ(x, 200);
    ASSERT_EQ(y, 204);
    ASSERT_EQ(z, 203);
}
